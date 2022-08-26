from setuptools import setup, Extension

setup(name="ForLoopModule",   
      version="1",    
      ext_modules=[Extension("ForLoopModule", ["FirstModule.c"])]  
      )