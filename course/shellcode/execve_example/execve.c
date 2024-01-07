__asm__(
    ".global run_sh\n"
    "run_sh:\n"

    "mov rax, 0x68732f6e69622f \n"
    "push rax\n"
    "mov rdi, rsp\n"
    "xor rsi, rsi\n"
    "xor rdx, rdx\n"
    "mov rax, 0x3b\n"
    "syscall"
    "\n"
    "xor rdi, rdi      # rdi = 0\n"
    "mov rax, 0x3c	   # rax = sys_exit\n"
    "syscall		   # exit(0)");

void run_sh();

int main() { run_sh(); }