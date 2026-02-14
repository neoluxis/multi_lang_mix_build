"""
Setup script for C++ Calculator Python bindings.
"""

import os
import sys
import subprocess
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext


class CMakeExtension(Extension):
    """CMake extension for building C++ Python bindings."""

    def __init__(self, name, sourcedir=''):
        Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)


class CMakeBuild(build_ext):
    """Custom build_ext command to build CMake extensions."""

    def run(self):
        try:
            subprocess.check_output(['cmake', '--version'])
        except OSError:
            raise RuntimeError("CMake must be installed to build the following extensions: " +
                             ", ".join(e.name for e in self.extensions))

        for ext in self.extensions:
            self.build_extension(ext)

    def build_extension(self, ext):
        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        cmake_args = ['-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=' + extdir,
                      '-DPYTHON_EXECUTABLE=' + sys.executable]

        cfg = 'Debug' if self.debug else 'Release'
        build_args = ['--config', cfg]

        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)

        # Configure CMake
        subprocess.check_call(['cmake', ext.sourcedir] + cmake_args,
                            cwd=self.build_temp)

        # Build the extension
        subprocess.check_call(['cmake', '--build', '.'] + build_args,
                            cwd=self.build_temp)


# Read README if it exists
this_directory = os.path.abspath(os.path.dirname(__file__))
readme_path = os.path.join(this_directory, 'README.md')
long_description = ""
if os.path.exists(readme_path):
    with open(readme_path, 'r', encoding='utf-8') as f:
        long_description = f.read()

setup(
    name="cpp-calculator",
    version="1.0.0",
    author="Your Name",
    author_email="your.email@example.com",
    description="Python bindings for C++ Calculator library",
    long_description=long_description,
    long_description_content_type="text/markdown",
    packages=["cpp_calculator"],
    package_dir={"cpp_calculator": "."},
    ext_modules=[CMakeExtension('cpp_calculator_py')],
    cmdclass=dict(build_ext=CMakeBuild),
    zip_safe=False,
    python_requires='>=3.6',
    classifiers=[
        "Development Status :: 4 - Beta",
        "Intended Audience :: Developers",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.6",
        "Programming Language :: Python :: 3.7",
        "Programming Language :: Python :: 3.8",
        "Programming Language :: Python :: 3.9",
        "Programming Language :: Python :: 3.10",
        "Programming Language :: Python :: 3.11",
        "Topic :: Scientific/Engineering :: Mathematics",
    ],
    keywords="calculator math cpp bindings pybind11",
    project_urls={
        "Bug Reports": "https://github.com/yourusername/mix_multi_lang/issues",
        "Source": "https://github.com/yourusername/mix_multi_lang",
    },
)