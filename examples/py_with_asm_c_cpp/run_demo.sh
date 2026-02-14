#!/bin/bash

# Python多语言库绑定示例运行脚本

echo "🌟 启动Python多语言库绑定示例"
echo "================================================================"

# 获取脚本所在目录的绝对路径
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(cd "$SCRIPT_DIR/../../" && pwd)"

echo "📁 项目根目录: $PROJECT_ROOT"
echo "📁 示例目录: $SCRIPT_DIR"
echo ""

# 检查构建目录是否存在
if [ ! -d "$PROJECT_ROOT/build" ]; then
    echo "❌ 错误: 构建目录不存在"
    echo "请先构建项目:"
    echo "  cd $PROJECT_ROOT"
    echo "  mkdir build && cd build"
    echo "  cmake .."
    echo "  make -j\$(nproc)"
    exit 1
fi

# 检查Python绑定是否存在
if [ ! -f "$PROJECT_ROOT/libs/c/bindings/python/c_math.cpython-314-x86_64-linux-gnu.so" ] || \
   [ ! -f "$PROJECT_ROOT/libs/asm/bindings/python/asm_math.cpython-314-x86_64-linux-gnu.so" ] || \
   [ ! -f "$PROJECT_ROOT/build/lib/python/cpp_calculator_py.cpython-314-x86_64-linux-gnu.so" ]; then
    echo "❌ 错误: Python绑定不存在"
    echo "请构建Python绑定:"
    echo "  cd $PROJECT_ROOT/libs/c/bindings/python && python3 setup.py build_ext --inplace"
    echo "  cd $PROJECT_ROOT/libs/asm/bindings/python && python3 setup.py build_ext --inplace"
    exit 1
fi

echo "✅ 所有文件检查通过"
echo ""

# 设置Python路径并运行示例（无需LD_LIBRARY_PATH！C和汇编库使用静态链接）
echo "🚀 运行示例..."
export PYTHONPATH="$PROJECT_ROOT/libs/c/bindings/python:$PROJECT_ROOT/libs/asm/bindings/python:$PROJECT_ROOT/build/lib/python:$PYTHONPATH"

cd "$SCRIPT_DIR"
python3 demo.py

echo ""
echo "🎊 示例运行完成！"