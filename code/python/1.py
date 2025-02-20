def print_pyc_header(pyc_file):
    with open('123.pyc', "rb") as f:
        header = f.read(16)  # 读取前 16 个字节
        print(f"Header: {header.hex()}")

# 使用示例
print_pyc_header("到梦空间-捡漏.pyc")