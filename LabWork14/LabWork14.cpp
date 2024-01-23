#include <bitset>
#include <iostream>
#include <cmath>
using namespace std;

void task1_1() {
    _asm {mov eax, 0xA1B2C3D4};
}

void task1_2() {
    _asm {mov ax, 7};
}

void task1_3() {
    char binaryNumber = 0;
    int eaxValue;
    _asm {
        mov al, 10b
        mov binaryNumber, al
        mov eaxValue, eax
    }
    cout << "Binary number: " << bitset<8>(static_cast<int>(binaryNumber)) << endl;
    cout << "EAX: " << bitset<32>(static_cast<int>(eaxValue)) << endl;
}

void task1_4() {
    short value = 0;
    _asm {
        mov bx, 3
        inc bx
        mov value, bx
    }
    cout << "BX: " << value << endl;

}

void task1_5() {
    unsigned short value = 0;
    _asm {
        mov bx, 3
        dec bx
        mov value, bx
    }
    cout << "BX: " << value << endl;
}

void task1_6() {
    unsigned int eaxVal = 0;
    unsigned int ebxVal = 0;
    _asm {
        mov eax, 5
        mov ebx, 2

        mov eaxVal, eax
        mov eax, ebx
        mov ebx, eaxVal

        mov eaxVal, eax
        mov ebxVal, ebx
    }
    cout << "eax Value: " << eaxVal << endl;
    cout << "ebx Value: " << ebxVal << endl;
}

void task1_7() {
    int eaxValue = 0;

    _asm {
        xor eax, eax
        mov al, 11111111b
        mov ah, al
        shl eax, 8; Сдвигаем eax на 16 бит вправо
        mov al, ah
        shl eax, 8; Сдвигаем eax на 16 бит вправо
        mov al, ah
        mov eaxValue, eax
    }

   /* _asm {
        xor eax, eax
        mov al, 11111111b
        mov ah, al
        shl eax, 16; Сдвигаем eax на 16 бит вправо
        mov al, 11111111b
        mov ah, al
        mov eaxValue, eax
    }*/

    std::cout << "EAX: " << bitset<32>(static_cast<int>(eaxValue)) << std::endl;
}

void task2() {
    int n;
    std::cout << "Enter the number of iterations: ";
    std::cin >> n;
    int result = 0; 

    _asm {
        mov eax, 0 // Zero out the EAX register
        mov ebx, n // Copy n into the EBX register

        start:
            add eax, 2 // Increase EAX by 2
            dec ebx // Decrease EBX by 1
            jnz start // Jump back to the start of the loop if EBX is not zero

        mov result, eax // Save the result
    }

    cout << "Result: " << result << endl;
}

void task3() {
    //std::cout << "Enter the first floating-point number: ";
    //std::cin >> num1;
    //std::cout << "Enter the second floating-point number: ";
    //std::cin >> num2;
    float num1 = 13.0;
    float num2 = 3.0;
    float res =0.0;
    float remainder;
    /*_asm {
        mov eax, num1
        mov ebx, num2
        div ebx 
        mul eax
        add eax, edx
        mov res, eax
    }*/
    // eax = частное, edx = остаток
    
   _asm {
       fld dword ptr[num1] // Загрузить num1 в стек FPU
       fdiv dword ptr[num2] // Делить num1 на num2
       fstp dword ptr[res] // Сохранить результат деления в res

       fld dword ptr[num1] // Загрузить num1 обратно в стек FPU
       fsub dword ptr[res] // Вычесть res из num1
       fstp dword ptr[remainder] // Сохранить остаток от деления в remainder

       fld dword ptr[res] // Загрузить res обратно в стек FPU
       fmul st(0), st(0) // Умножить res на самого себя
       fadd dword ptr[remainder] // Добавить remainder к результату умножения
       fstp dword ptr[res] // Сохранить окончательный результат в res
   };

    std::cout << "Результат: " << res << std::endl;

    double quotient1 = floor(num1 / num2);  // Вычисление частного
    double remainder1 = fmod(num1, num2);  // Вычисление остатка
    double result = quotient1 * quotient1 + remainder1;  // Умножение частного на число и добавление остатка
    std::cout << "Результат: " << result << std::endl;
}

int main()
{
    //task1_1();
    //task1_2();
    //task1_3();
    //task1_4();
    //task1_5();
    //task1_6();
    //task1_7();
    //task2(); 
    task3(); //dw
}


