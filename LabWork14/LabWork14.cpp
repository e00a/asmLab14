#include <bitset>
#include <iostream>
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
    double num1, num2;
    float quotient, remainder, result;

    std::cout << "Enter the first floating-point number: ";
    std::cin >> num1;

    std::cout << "Enter the second floating-point number: ";
    std::cin >> num2;

    _asm {
        fld num1
        fdiv num2
        fstp quotient
    }
    _asm {
        fld num1
        fmul quotient
        fadd remainder
        fstp result
    }

    cout << "Result: " << result << endl;
}

int main()
{
    task1_1();
    task1_2();
    task1_3();
    task1_4();
    task1_5();
    task1_6();
    task1_7(); //dont work
    task2(); 
    task3(); //dw
}


