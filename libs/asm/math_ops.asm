; math_ops.asm - x64 汇编实现的数学运算函数
; 使用 System V AMD64 ABI 调用约定

section .text
global asm_add
global asm_subtract
global asm_multiply
global asm_factorial
global asm_power
global asm_bitwise_and
global asm_bitwise_or
global asm_left_shift

; int64_t asm_add(int64_t a, int64_t b)
; 参数: rdi = a, rsi = b
; 返回: rax
asm_add:
    mov rax, rdi        ; 将第一个参数移到rax
    add rax, rsi        ; 加第二个参数
    ret

; int64_t asm_subtract(int64_t a, int64_t b)
; 参数: rdi = a, rsi = b
; 返回: rax
asm_subtract:
    mov rax, rdi        ; 将第一个参数移到rax
    sub rax, rsi        ; 减第二个参数
    ret

; int64_t asm_multiply(int64_t a, int64_t b)
; 参数: rdi = a, rsi = b
; 返回: rax
asm_multiply:
    mov rax, rdi        ; 将第一个参数移到rax
    imul rax, rsi       ; 有符号乘法
    ret

; uint64_t asm_factorial(uint32_t n)
; 参数: edi = n (32位)
; 返回: rax
asm_factorial:
    mov ecx, edi        ; 将n移到ecx作为计数器
    mov rax, 1          ; 初始化结果为1
    cmp ecx, 0          ; 检查n是否为0
    je .done            ; 如果是，返回1

.loop:
    imul rax, rcx       ; 乘以当前计数器
    dec ecx             ; 计数器减1
    jnz .loop           ; 如果不为0，继续循环

.done:
    ret

; uint64_t asm_power(uint32_t base, uint32_t exp)
; 参数: edi = base, esi = exp
; 返回: rax
asm_power:
    mov eax, 1          ; 初始化结果为1
    mov ecx, esi        ; 将exp移到ecx作为计数器
    test ecx, ecx       ; 检查exp是否为0
    jz .done_power      ; 如果是，返回1

.power_loop:
    imul rax, rdi       ; 乘以base
    dec ecx             ; 计数器减1
    jnz .power_loop     ; 继续循环

.done_power:
    ret

; uint64_t asm_bitwise_and(uint64_t a, uint64_t b)
; 参数: rdi = a, rsi = b
; 返回: rax
asm_bitwise_and:
    mov rax, rdi        ; 将a移到rax
    and rax, rsi        ; 位与操作
    ret

; uint64_t asm_bitwise_or(uint64_t a, uint64_t b)
; 参数: rdi = a, rsi = b
; 返回: rax
asm_bitwise_or:
    mov rax, rdi        ; 将a移到rax
    or rax, rsi         ; 位或操作
    ret

; uint64_t asm_left_shift(uint64_t value, int shift)
; 参数: rdi = value, esi = shift
; 返回: rax
asm_left_shift:
    mov rax, rdi        ; 将value移到rax
    mov cl, sil         ; 将shift移到cl (8位)
    shl rax, cl         ; 左移操作
    ret