"""
Setup script for Cython-based Assembly math operations bindings.
"""

from setuptools import setup, Extension
from Cython.Build import cythonize
import os

# Define the extension module
extensions = [
    Extension(
        "asm_math",
        sources=["asm_math.pyx"],
        include_dirs=[
            os.path.join(os.path.dirname(__file__), '..', '..', 'include'),
        ],
        extra_objects=[
            os.path.join(os.path.dirname(__file__), '..', '..', '..', '..', 'build', 'lib', 'libasm_math_ops.a'),
        ],
        extra_compile_args=["-O3"],
    )
]

setup(
    name="asm_math_ops",
    version="1.0.0",
    description="Cython bindings for Assembly math operations library",
    ext_modules=cythonize(extensions, language_level=3),
    python_requires='>=3.6',
)