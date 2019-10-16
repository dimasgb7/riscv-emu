#!/pkg/OSS-anaconda-/4.2.0/x86_64-linux/bin/python

__version__ = "0.0.1"

import pprint
import os
import csv
import sys
import configparser
import argparse
import subprocess
import gzip
import xlrd
from lxml import etree
from collections import OrderedDict, defaultdict
from copy import deepcopy
import re

sys.dont_write_bytecode = True   # making sure python will not create a pyc file
sys.path.insert(1,os.path.dirname(__file__))
#from argactions import *
#from mcu_base import *


class SIM_gen():
    def __init__(self):
        super(SIM_gen, self).__init__()

        self._summary_fd = None
        self.verbose = False
        self.map_d = {}

    def create_file_header(self):
      content  = '// WARNING!!! THIS FILE IS AUTO GENERATED, DO NOT EDIT!!!\n'
      content += '// file generated using the following command:\n'
      content += '// %s\n\n' % ' '.join(sys.argv)

      return content

    def run(self, call_parse_args=True, args=None):

        try:
            #change current working directory
            if os.path.dirname(__file__):
                os.chdir(os.path.dirname(__file__))
          
            #Open Register Methods File
            self.map_file ='dummy_func_file'
            destination_file_reg = open(self.map_file,'w')

            #RTD_SIM 
            self.src_file_name = "sim_csv/rtd_def.csv"
            sheet_d = self.get_dict_from_csv(self.src_file_name,'name')

            
            self.map_file ='rtd_sim_utils.h'
            destination_file = open(self.map_file,'w')
            
            content  = self.create_file_header()
            content +=self.create_header("RTD_SIM")
            content +=self.create_header_c("RTD_SIM_UTILS")
          
            content +=self.create_sim_defines(sheet_d,"RTD_SIM")
            
            content +="\n"
            content +="#endif"
            destination_file.write(content)            
            destination_file.close()
            content = ""
            
            #CREATING RTD REGISTER METHODS 
            content_reg = self.create_header("RTD register check")
            content_reg += self.create_sim_functions(sheet_d,"RTD_SIM")
           
            #APD_SIM
            self.src_file_name = "sim_csv/apd_def.csv"
            sheet_d = self.get_dict_from_csv(self.src_file_name,'name')

            self.map_file ='apd_sim_utils.h'
            destination_file = open(self.map_file,'w')
            
            content  = self.create_file_header()
            content +=self.create_header("APD_SIM")
            content +=self.create_header_c("APD_SIM_UTILS")
          
            content +=self.create_sim_defines(sheet_d,"APD_SIM")
            
            content +="\n"
            content +="#endif"
            destination_file.write(content)            
            destination_file.close()
            content = ""
            
            #CREATING APD REGISTER METHODS
            content_reg += self.create_header("APD register check")
            content_reg += self.create_sim_functions(sheet_d,"APD_SIM")
            

            #AVD_SIM
            self.src_file_name = "sim_csv/avd_def.csv"
            sheet_d = self.get_dict_from_csv(self.src_file_name,'name')

            
            self.map_file ='avd_sim_utils.h'
            destination_file = open(self.map_file,'w')
            
            content  = self.create_file_header()
            content +=self.create_header("AVD_SIM")
            content +=self.create_header_c("AVD_SIM_UTILS")
          
            content +=self.create_sim_defines(sheet_d,"AVD_SIM")
            
            content +="\n"
            content +="#endif"
            destination_file.write(content)            
            destination_file.close()
            content = ""

            #CREATING AVD REGISTER METHODS
            content_reg += self.create_header("AVD register check")
            content_reg += self.create_sim_functions(sheet_d,"AVD_SIM")
            

            #RTD_SEC_SIM
            self.src_file_name = "sim_csv/rtd_sec_def.csv"
            sheet_d = self.get_dict_from_csv(self.src_file_name,'name')

            
            self.map_file ='rtd_sec_sim_utils.h'
            destination_file = open(self.map_file,'w')
            
            content  = self.create_file_header()
            content +=self.create_header("RTD_SEC_SIM")
            content +=self.create_header_c("RTD_SEC_SIM_UTILS")
          
            content +=self.create_sim_defines(sheet_d,"RTD_SEC_SIM")
            
            content +="\n"
            content +="#endif"
            destination_file.write(content)            
            destination_file.close()
            content = ""
            
            #CREATING RTD_SEC REGISTER METHOS s
            content_reg += self.create_header("RTD_SEC register check")
            content_reg += self.create_sim_functions(sheet_d,"RTD_SEC_SIM")
           
            #Closing Registher Methods File
            destination_file_reg.write(content_reg)            
            destination_file_reg.close()
            content = ""

       
            '''
           #CREATING REGISTER METHODS
            
            ''' 
            return "SIM register utils generated"

        except (KeyboardInterrupt):
            self._log(self._SOLOG, "\n\nGeneration terminated early with ctrl-c\n")
            return self.FAIL
        except (SystemExit) as e:
            self._log(self._SOLOG, "%s\n exiting\n\n\n"%e)
            return self.FAIL
        #except Exception as e:
        #    self._log(self._SOLOG, "%s\n exiting\n\n\n"%e)
        #    return self.FAIL
    
    
            
        
    def get_dict_from_csv(self, src_file_name, header_identifier):
        sheet_d = {}
        xls_d = OrderedDict()
        #Open file and set and set a proper newline argument according to the table provided
        s_f = open(src_file_name, 'r',newline='')
        workbook = list(s_f) 

        header_position = None
        lines = len(workbook)

        for line in range(lines):
           if header_identifier in workbook[line]:
              header_position = line
              break

        if header_position == None:
           self._log(self._SOLOGERR, "ERROR: could not find the table's header\n", True, 'red-bold')
         
        header = workbook[header_position].split(',')

        # Correct some columns not filled.
        ##header = header[:-4]
        
        for r_index in range(header_position,lines):
           xls_d[r_index] = OrderedDict()
           cell_value = workbook[r_index].split(',')
           
           for c_index in range(len(header)):
        # Make sure every colum defined on header is 
                                    #evaluated on each line
              if (c_index < len(cell_value)):
                 xls_d[r_index][header[c_index]] = cell_value[c_index]
              else:
                 xls_d[r_index][header[c_index]] = ''
        
        sheet_d['xls_d'] = xls_d
        sheet_d['header_position'] = header_position
        sheet_d['nrows'] = lines
        sheet_d['header'] = header
        
        #pp = pprint.PrettyPrinter(indent=2)
        #pp.pprint(sheet_d)
        return sheet_d

    def create_header(self, string):
        content  = '//------------------------------------------------------------\n'
        content += "// %s \n" % string
        content += '//------------------------------------------------------------\n\n'

        return content
    
    def create_header_c(self, string):
        content  = "#ifndef %s_H\n" % string
        content += "#define %s_H\n" % string
        content += '#define %s_HEADER "%s.h" \n' % (string,string)
        content += '//------------------------------------------------------------\n\n'

        return content

    def create_sim_functions(self, input_map_d, string):
    
        content = ""
        
        my_map_d = input_map_d['xls_d']
        n_lines = len(my_map_d) 
        
        function_head="void %s_reg_check_reset(SIM_CONTEXT* sim_context){\n" % string.lower()
        
        content += function_head
        for line in range(1,n_lines):
            my_line = my_map_d[line]
            my_name = my_line['name']
            reset_method = "RE32(%s_%s,         %s_%s_RST);\n" %(string,my_name,string,my_name)
            content += reset_method
        
        content +="\n}\n"
        
        function_head="void %s_reg_write_complement_32(SIM_CONTEXT* sim_context, uint32_t wr_val){\n" % string.lower()
        
        content += function_head
       
        for line in range(1,n_lines):
            my_line = my_map_d[line]
            my_name = my_line['name']
            reset_method = "WRE32(%s_%s,        wr_val,(wr_val & %s_%s_WMASK));\n" %(string,my_name,string,my_name)
            content += reset_method
        
        content +="\n}\n"
        
        reg_list_head = "uint32_t %s_regs [] = { " % string.lower()
        content += reg_list_head
        for line in range(1,n_lines):
            my_line = my_map_d[line]
            my_name = my_line['name']
            reg_list= "%s_%s_ADDR,\n" %(string,my_name)
            content += reg_list
            
        content = content[0:-1-2]
        content +="\n}\n"



        return content
    
    def create_sim_defines(self, input_map_d, string):
        
        content = ""
        
        my_map_d = input_map_d['xls_d']
        n_lines = len(my_map_d) 
         
        for line in range(1,n_lines):
            my_line = my_map_d[line]
            my_offset = my_line['offset']
            my_name = my_line['name']
            offset = "#define %s_%s_OFFSET          0x%s\n" %(string,my_name,my_offset)
            content += offset
       
        my_str_offset = my_offset 
        my_hex_offset = int(my_str_offset,16) 
        my_unimplemented_reg = my_hex_offset + 0x4   
        
        
        content +="\n\n"
        content += "#define %s_UNIMPLEMENTED_BEGIN          0x%X \n" % (string,my_unimplemented_reg)
        content +="\n"
        

        for line in range (1,n_lines):
            my_line = my_map_d[line]
            my_name = my_line['name']
            register = "#define %s_%s_ADDR   %s_REGS_BASE + %s_%s_OFFSET\n" \
                                        %(string,my_name,string,string,my_name)
                                        
            content += register
        
        content +="\n"
        
        for line in range (1,n_lines):
            my_line = my_map_d[line]
            my_name = my_line['name']
            register = "#define %s_%s   REG32(%s_%s_ADDR)\n" \
                                        %(string,my_name,string,my_name)
                                        
            content += register 
        
        content += self.create_header("REGISTERS RESET DEFINITION")
        
        for line in range (1,n_lines):
            my_line = my_map_d[line]
            my_name = my_line['name']
            my_reset = my_line['reset']
            reset = "#define %s_%s_RST          0x%s\n" % (string,my_name,my_reset)  
            
            content += reset
        
        content += self.create_header("REGISTERS RMASK DEFINITION")
        
        for line in range (1,n_lines):
            my_line = my_map_d[line]
            my_name = my_line['name']
            my_mask = my_line['rmask']
            rmask    = "#define %s_%s_RMASK           0x%s\n" % (string,my_name,my_mask) 
           
            content += rmask
        
        content += self.create_header("REGISTERS WMASK DEFINITION")
        
        for line in range (1,n_lines):
            my_line = my_map_d[line]
            my_name = my_line['name']
            my_mask = my_line['wmask']
            wmask    = "#define %s_%s_WMASK           0x%s\n" % (string,my_name,my_mask) 
           
            content += wmask
        
        return content


if __name__ == '__main__':
    generator = SIM_gen()
    retval = generator.run()
    sys.exit(retval)
