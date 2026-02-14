from setuptools import setup, find_packages

setup(
    name="asm_math_ops",
    version="1.0.0",
    description="Python bindings for Assembly math operations library",
    packages=find_packages(),
    package_data={
        'asm_math_ops': ['*.so', '*.dll', '*.dylib'],
    },
    python_requires='>=3.6',
)