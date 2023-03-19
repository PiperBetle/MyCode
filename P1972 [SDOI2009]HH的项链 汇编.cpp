#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	fwrite(obuf,p3-obuf,1,stdout);
	__asm{
		ibuf:
        .zero   1000007
p1:
        .quad   ibuf
p2:
        .quad   ibuf
obuf:
        .zero   1000007
p3:
        .quad   obuf
sta:
        .zero   200
read():
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movl    $0, -4(%rbp)
        movl    $1, -8(%rbp)
        call    getchar
        movl    %eax, -12(%rbp)
        jmp     .L4
.L6:
        cmpl    $45, -12(%rbp)
        jne     .L5
        movl    $-1, -8(%rbp)
.L5:
        call    getchar
        movl    %eax, -12(%rbp)
.L4:
        movl    -12(%rbp), %eax
        subl    $48, %eax
        cmpl    $9, %eax
        ja      .L6
        jmp     .L7
.L8:
        movl    -4(%rbp), %edx
        movl    %edx, %eax
        sall    $2, %eax
        addl    %edx, %eax
        addl    %eax, %eax
        movl    -12(%rbp), %edx
        xorl    $48, %edx
        addl    %edx, %eax
        movl    %eax, -4(%rbp)
        call    getchar
        movl    %eax, -12(%rbp)
.L7:
        movl    -12(%rbp), %eax
        subl    $48, %eax
        cmpl    $9, %eax
        jbe     .L8
        movl    -4(%rbp), %eax
        imull   -8(%rbp), %eax
        leave
        ret
write(int):
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $32, %rsp
        movl    %edi, -20(%rbp)
        cmpl    $0, -20(%rbp)
        jne     .L11
        movl    $48, %edi
        call    putchar
        jmp     .L10
.L11:
        movl    $0, -4(%rbp)
        cmpl    $0, -20(%rbp)
        jns     .L13
        negl    -20(%rbp)
        movl    $45, %edi
        call    putchar
.L13:
        jmp     .L14
.L15:
        movl    -4(%rbp), %esi
        leal    1(%rsi), %eax
        movl    %eax, -4(%rbp)
        movl    -20(%rbp), %ecx
        movl    $1717986919, %edx
        movl    %ecx, %eax
        imull   %edx
        sarl    $2, %edx
        movl    %ecx, %eax
        sarl    $31, %eax
        subl    %eax, %edx
        movl    %edx, %eax
        sall    $2, %eax
        addl    %edx, %eax
        addl    %eax, %eax
        subl    %eax, %ecx
        movl    %ecx, %edx
        addl    $48, %edx
        movslq  %esi, %rax
        movl    %edx, sta(,%rax,4)
        movl    -20(%rbp), %ecx
        movl    $1717986919, %edx
        movl    %ecx, %eax
        imull   %edx
        sarl    $2, %edx
        movl    %ecx, %eax
        sarl    $31, %eax
        subl    %eax, %edx
        movl    %edx, %eax
        movl    %eax, -20(%rbp)
.L14:
        cmpl    $0, -20(%rbp)
        jne     .L15
        jmp     .L16
.L17:
        movl    -4(%rbp), %eax
        cltq
        movl    sta(,%rax,4), %eax
        movl    %eax, %edi
        call    putchar
.L16:
        movl    -4(%rbp), %eax
        leal    -1(%rax), %edx
        movl    %edx, -4(%rbp)
        testl   %eax, %eax
        setne   %al
        testb   %al, %al
        jne     .L17
.L10:
        leave
        ret
ask::operator<(ask const&) const:
        pushq   %rbp
        movq    %rsp, %rbp
        movq    %rdi, -8(%rbp)
        movq    %rsi, -16(%rbp)
        movq    -8(%rbp), %rax
        movl    4(%rax), %edx
        movq    -16(%rbp), %rax
        movl    4(%rax), %eax
        cmpl    %eax, %edx
        setl    %al
        popq    %rbp
        ret
q:
        .zero   12000084
s:
        .zero   4000028
n:
        .zero   4
m:
        .zero   4
a:
        .zero   4000028
vis:
        .zero   4000028
ans:
        .zero   4000028
lowbit(int):
        pushq   %rbp
        movq    %rsp, %rbp
        movl    %edi, -4(%rbp)
        movl    -4(%rbp), %eax
        negl    %eax
        andl    -4(%rbp), %eax
        popq    %rbp
        ret
add(int, int):
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movl    %edi, -4(%rbp)
        movl    %esi, -8(%rbp)
        jmp     .L23
.L24:
        movl    -4(%rbp), %eax
        cltq
        movl    s(,%rax,4), %edx
        movl    -8(%rbp), %eax
        addl    %eax, %edx
        movl    -4(%rbp), %eax
        cltq
        movl    %edx, s(,%rax,4)
        movl    -4(%rbp), %eax
        movl    %eax, %edi
        call    lowbit(int)
        addl    %eax, -4(%rbp)
.L23:
        movl    n(%rip), %eax
        cmpl    %eax, -4(%rbp)
        jle     .L24
        leave
        ret
query(int, int):
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movl    %edi, -4(%rbp)
        movl    %esi, -8(%rbp)
        jmp     .L26
.L27:
        movl    -4(%rbp), %eax
        cltq
        movl    s(,%rax,4), %eax
        addl    %eax, -8(%rbp)
        movl    -4(%rbp), %eax
        movl    %eax, %edi
        call    lowbit(int)
        subl    %eax, -4(%rbp)
.L26:
        cmpl    $0, -4(%rbp)
        jne     .L27
        movl    -8(%rbp), %eax
        leave
        ret
main:
        pushq   %rbp
        movq    %rsp, %rbp
        pushq   %r12
        pushq   %rbx
        subq    $16, %rsp
        movl    $1, -24(%rbp)
        call    read()
        movl    %eax, n(%rip)
        movl    $1, -20(%rbp)
        jmp     .L30
.L31:
        call    read()
        movl    -20(%rbp), %edx
        movslq  %edx, %rdx
        movl    %eax, a(,%rdx,4)
        addl    $1, -20(%rbp)
.L30:
        movl    n(%rip), %eax
        cmpl    %eax, -20(%rbp)
        jle     .L31
        call    read()
        movl    %eax, m(%rip)
        movl    $1, -20(%rbp)
        jmp     .L32
.L33:
        call    read()
        movl    %eax, %ecx
        movl    -20(%rbp), %eax
        movslq  %eax, %rdx
        movq    %rdx, %rax
        addq    %rax, %rax
        addq    %rdx, %rax
        salq    $2, %rax
        addq    $q, %rax
        movl    %ecx, (%rax)
        call    read()
        movl    %eax, %ecx
        movl    -20(%rbp), %eax
        movslq  %eax, %rdx
        movq    %rdx, %rax
        addq    %rax, %rax
        addq    %rdx, %rax
        salq    $2, %rax
        addq    $q, %rax
        movl    %ecx, 4(%rax)
        movl    -20(%rbp), %eax
        movslq  %eax, %rdx
        movq    %rdx, %rax
        addq    %rax, %rax
        addq    %rdx, %rax
        salq    $2, %rax
        leaq    q(%rax), %rdx
        movl    -20(%rbp), %eax
        movl    %eax, 8(%rdx)
        addl    $1, -20(%rbp)
.L32:
        movl    m(%rip), %eax
        cmpl    %eax, -20(%rbp)
        jle     .L33
        movl    m(%rip), %eax
        cltq
        leaq    1(%rax), %rdx
        movq    %rdx, %rax
        addq    %rax, %rax
        addq    %rdx, %rax
        salq    $2, %rax
        addq    $q, %rax
        movq    %rax, %rsi
        movl    $q+12, %edi
        call    void std::sort<ask*>(ask*, ask*)
        movl    $1, -20(%rbp)
        jmp     .L34
.L38:
        jmp     .L35
.L37:
        movl    -24(%rbp), %eax
        cltq
        movl    a(,%rax,4), %eax
        cltq
        movl    vis(,%rax,4), %eax
        testl   %eax, %eax
        je      .L36
        movl    -24(%rbp), %eax
        cltq
        movl    a(,%rax,4), %eax
        cltq
        movl    vis(,%rax,4), %eax
        movl    $-1, %esi
        movl    %eax, %edi
        call    add(int, int)
.L36:
        movl    -24(%rbp), %eax
        cltq
        movl    a(,%rax,4), %eax
        movslq  %eax, %rdx
        movl    -24(%rbp), %ecx
        movl    %ecx, vis(,%rdx,4)
        cltq
        movl    vis(,%rax,4), %eax
        movl    $1, %esi
        movl    %eax, %edi
        call    add(int, int)
        addl    $1, -24(%rbp)
.L35:
        movl    -20(%rbp), %eax
        movslq  %eax, %rdx
        movq    %rdx, %rax
        addq    %rax, %rax
        addq    %rdx, %rax
        salq    $2, %rax
        addq    $q, %rax
        movl    4(%rax), %eax
        cmpl    -24(%rbp), %eax
        jge     .L37
        movl    -20(%rbp), %eax
        movslq  %eax, %rdx
        movq    %rdx, %rax
        addq    %rax, %rax
        addq    %rdx, %rax
        salq    $2, %rax
        addq    $q, %rax
        movl    8(%rax), %r12d
        movl    -20(%rbp), %eax
        movslq  %eax, %rdx
        movq    %rdx, %rax
        addq    %rax, %rax
        addq    %rdx, %rax
        salq    $2, %rax
        addq    $q, %rax
        movl    4(%rax), %eax
        movl    $0, %esi
        movl    %eax, %edi
        call    query(int, int)
        movl    %eax, %ebx
        movl    -20(%rbp), %eax
        movslq  %eax, %rdx
        movq    %rdx, %rax
        addq    %rax, %rax
        addq    %rdx, %rax
        salq    $2, %rax
        addq    $q, %rax
        movl    (%rax), %eax
        subl    $1, %eax
        movl    $0, %esi
        movl    %eax, %edi
        call    query(int, int)
        subl    %eax, %ebx
        movl    %ebx, %edx
        movslq  %r12d, %rax
        movl    %edx, ans(,%rax,4)
        addl    $1, -20(%rbp)
.L34:
        movl    m(%rip), %eax
        cmpl    %eax, -20(%rbp)
        jle     .L38
        movl    $1, -20(%rbp)
        jmp     .L39
.L40:
        movl    -20(%rbp), %eax
        cltq
        movl    ans(,%rax,4), %eax
        movl    %eax, %edi
        call    write(int)
        movl    $10, %edi
        call    putchar
        addl    $1, -20(%rbp)
.L39:
        movl    m(%rip), %eax
        cmpl    %eax, -20(%rbp)
        jle     .L40
        movq    stdout(%rip), %rdx
        movq    p3(%rip), %rax
        movq    %rax, %rcx
        movl    $obuf, %eax
        subq    %rax, %rcx
        movq    %rcx, %rax
        movq    %rdx, %rcx
        movl    $1, %edx
        movq    %rax, %rsi
        movl    $obuf, %edi
        call    fwrite
        movl    $0, %eax
        addq    $16, %rsp
        popq    %rbx
        popq    %r12
        popq    %rbp
        ret
__static_initialization_and_destruction_0(int, int):
        pushq   %rbp
        movq    %rsp, %rbp
        subq    $16, %rsp
        movl    %edi, -4(%rbp)
        movl    %esi, -8(%rbp)
        cmpl    $1, -4(%rbp)
        jne     .L126
        cmpl    $65535, -8(%rbp)
        jne     .L126
        movl    $_ZStL8__ioinit, %edi
        call    std::ios_base::Init::Init() [complete object constructor]
        movl    $__dso_handle, %edx
        movl    $_ZStL8__ioinit, %esi
        movl    $_ZNSt8ios_base4InitD1Ev, %edi
        call    __cxa_atexit
.L126:
        leave
        ret
_GLOBAL__sub_I_ibuf:
        pushq   %rbp
        movq    %rsp, %rbp
        movl    $65535, %esi
        movl    $1, %edi
        call    __static_initialization_and_destruction_0(int, int)
        popq    %rbp
        ret
	}
	return 0;
}