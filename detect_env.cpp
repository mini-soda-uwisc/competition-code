#include <iostream>

int main() {
    std::cout << "=== 环境检测信息 ===" << std::endl;

    // 检测编译器
#if defined(__clang__)
    std::cout << "编译器: Clang" << std::endl;
#elif defined(__GNUC__) || defined(__GNUG__)
    std::cout << "编译器: GCC" << std::endl;
#elif defined(_MSC_VER)
    std::cout << "编译器: MSVC" << std::endl;
#else
    std::cout << "编译器: 未知" << std::endl;
#endif

    // 检测操作系统
#if defined(_WIN32)
    std::cout << "操作系统: Windows (32/64-bit)" << std::endl;
#elif defined(_WIN64)
    std::cout << "操作系统: Windows (64-bit)" << std::endl;
#elif defined(__APPLE__) && defined(__MACH__)
    std::cout << "操作系统: macOS" << std::endl;
#elif defined(__linux__)
    std::cout << "操作系统: Linux" << std::endl;
#elif defined(__unix__)
    std::cout << "操作系统: Unix" << std::endl;
#else
    std::cout << "操作系统: 未知" << std::endl;
#endif

    // 检测是否为64位系统
#if defined(__x86_64__) || defined(_M_X64)
    std::cout << "系统架构: 64-bit" << std::endl;
#elif defined(__i386__) || defined(_M_IX86)
    std::cout << "系统架构: 32-bit" << std::endl;
#elif defined(__aarch64__)
    std::cout<< "系统架构: ARM 64-bit" << std::endl;
#else
    std::cout << "系统架构: 未知" << std::endl;
#endif

    return 0;
}
