from setuptools import setup, Extension

setup(name="ExpModule",   
      version="1",    
      ext_modules=[Extension("ExpModule", ["SecondModule.c"])]   
      )
