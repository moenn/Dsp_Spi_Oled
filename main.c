/*
代码和详细说明托管在: https://github.com/moenn/Dsp_Spi_Oled
简要说明:
改变    #define EXAMPLE_SELECT 1 的值(1-7)来激活不同的函数.
*/
#include "my_oled.h"
#include "DSP28x_Project.h"


#define EXAMPLE_SELECT 1
// 测试屏幕
void Example1(void);
// 在屏幕上显示内容
void Example2(void);
void Example3(void);
void Example4(void);
// 清除屏幕上显示的内容
void Example5(void);
void Example6(void);
void Example7(void);

int main(void)
{
    InitSysCtrl();
    // 初始化 OLED
    InitOledGpio();
    InitOled();
    // 清屏
    OledClear();


    switch(EXAMPLE_SELECT)
    {
        case 1:
            Example1();
            break;
        case 2:
            Example2();
            break;
        case 3:
            Example3();
            break;
        case 4:
            Example4();
            break;
        case 5:
            Example5();
            break;
        case 6:
            Example6();
            break;
        case 7:
            Example7();
            break;
        default:
            ;
    }

}

// 测试屏幕
void Example1(void)
{
    OledClear();
    for(;;)
    {
        OledTest();
    }
}

// 输出单个字符
void Example2(void)
{
    OledClear();
    // 第0行
    OledPutChar(0, 0, 'H');
    OledPutChar(0, 1, 'e');
    OledPutChar(0, 2, 'l');
    OledPutChar(0, 3, 'l');
    OledPutChar(0, 4, 'o');
    OledPutChar(0, 5, ' ');
    OledPutChar(0, 6, 'W');
    OledPutChar(0, 7, 'o');
    OledPutChar(0, 8, 'r');
    OledPutChar(0, 9, 'l');
    OledPutChar(0, 10, 'd');
    OledPutChar(0, 11, '!');
    // 第1行
    OledPutChar(1, 0, '0');
    OledPutChar(1, 1, '1');
    OledPutChar(1, 2, '2');
    OledPutChar(1, 3, '3');
    OledPutChar(1, 4, '4');
    OledPutChar(1, 5, '5');
    OledPutChar(1, 6, '6');
    OledPutChar(1, 7, '7');
    OledPutChar(1, 8, '8');
    OledPutChar(1, 9, '9');
    // 第2行
    OledPutChar(2, 0, '!');
    OledPutChar(2, 1, '@');
    OledPutChar(2, 2, '#');
    OledPutChar(2, 3, '$');
    OledPutChar(2, 4, '%');
    OledPutChar(2, 5, '^');
    OledPutChar(2, 6, '&');
    OledPutChar(2, 7, '*');
    OledPutChar(2, 8, '(');
    OledPutChar(2, 9, ')');
    OledPutChar(2, 10, '+');
    OledPutChar(2, 11, '-');
    OledPutChar(2, 12, '[');
    OledPutChar(2, 13, ']');
    OledPutChar(2, 14, ';');
    OledPutChar(2, 15, ':');
}

// 输出字符串
void Example3(void)
{
    OledClear();
    OledPutWord(0, 0, "She walks in Beauty, like the night. --- George Gordon Byron");
}

// 输出数字
void Example4(void)
{
    OledClear();
    OledPutNumber(0, 0, -2147483648);
    OledPutNumber(1, 0, 2147483647);
    OledPutNumber(2, 0, 233);
    OledPutNumber(3, 0, 120);
}

// 依序清除字符串中的某个字符
void Example5(void)
{
    unsigned char i;

    OledClear();
    while(1)
    {
        OledPutWord(0, 0, "longlonglongword");
        for(i=0;i<16;i++)
        {
            DELAY_US(100000);
            OledClearChar(0, i);
        }
    }

}

// 在第0行，从第4列清除至第8列
void Example6(void)
{
    OledClear();
    while(1)
    {
        OledPutWord(0, 0, "longlonglongword");
        DELAY_US(500000);
        OledClearRowPartial(0, 4, 8);
        DELAY_US(500000);
    }
}

// 在第0行，从第4列清除至行尾
void Example7(void)
{
    OledClear();
    while(1)
    {
        OledPutWord(0, 0, "longlonglongword");
        DELAY_US(500000);
        OledClearToRowEnd(0, 4);
        DELAY_US(500000);
    }
}


