#include <stdio.h>

#include "ft_printf.c"

int main()
{
    printf("# %%d\n");
    ft_printf("%d ", 2147483647);    
    ft_printf("%d ", -1);    
    ft_printf("%d ", -2147483648);    
    ft_printf("%d ", 1234);    
    ft_printf("%d ", 0);    

    printf("# %%i\n");
    ft_printf("%i ", 2147483647);    
    ft_printf("%i ", -1);    
    ft_printf("%i ", -2147483648);    
    ft_printf("%i ", 1234);    
    ft_printf("%i ", 0);    
    
    printf("# %%u\n");
    ft_printf("%u ", 2147483648);    
    ft_printf("%u ", -1);    
    ft_printf("%u ", -2);    
    ft_printf("%u ", 0);    
    ft_printf("%u ", 1234567);    

    printf("# %%s\n");
    ft_printf("%s ", "Hello World");    
    ft_printf("%s ", "NULL");    
    ft_printf("%s ", NULL);    
    ft_printf("%s ", "42");    
    ft_printf("%s ", "");    

    printf("# %%c\n");
    ft_printf("%c ", 'c');    
    ft_printf("%c ", 'a');    
    ft_printf("%c ", '');    
    ft_printf("%c ", '0');    
    ft_printf("%c ", NULL);    

    printf("# %%x\n");
    ft_printf("%x ", 1234);    
    ft_printf("%x ", 2147483647);    
    ft_printf("%x ", 0);    
    ft_printf("%x ", -1);    
    ft_printf("%x ", 1);    

    printf("# %%X\n");
    ft_printf("%X ", 2147483647);    
    ft_printf("%X ", 0);    
    ft_printf("%X ", 1);    
    ft_printf("%X ", -1);    
    ft_printf("%X ", 1234);    

    printf("# %%p\n");
    ft_printf("%p ", "1");    
    ft_printf("%p ", NULL);    
    ft_printf("%p ", 2147483647);    
    ft_printf("%p ", "1234");    
    ft_printf("%p ", "12412412412414");    

    printf("# %%\n");
    ft_printf("%% " );    


}
    