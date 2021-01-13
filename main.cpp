/*
Гребенков Дмитрий М8О-207Б-19
ЛР 2 Вариант 1
Комплексное число в алгебраической форме представляются парой действительных чисел (a, b), 
где a - действительная часть, b - мнимая часть. Реализовать класс Complex для работы с комплексными числами.
Обязательно должны быть присутствовать операции
-              сложения add, (a, b) + (c, d) = (a + c, b + d);
-              вычитания sub, (a, b) – (c, d) = (a – c, b – d);
-              умножения mul, (a, b) ´ (c, d) = (ac – bd, ad + bc);
-              деления div, (a, b) / (c, d) = (ac + bd, bc – ad) / (c2 + d2); 
-              сравнение equ, (a, b) = (c, d), если (a = c) и (b = d);
-              сопряженное число conj, conj(a, b) = (a, –b). 
Реализовать операции сравнения модулей. 
Операции сложения, вычитания, умножения, деления, сравнения на равенство должны быть выполнены в виде
перегрузки операторов. 
Необходимо реализовать пользовательский литерал для работы с константами типа Complex.
*/

#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

class Complex {
    public:
        Complex () {}
        Complex (double x, double y) {
        a = x;
        b = y;
        }
        double getRe () {
            return a;
        }
        double getIm () {
            return b;
        }
        void set (double x, double y) {
            a = x;
            b = y;
        }
        void add (Complex x) {
            a += x.a;
            b += x.b;
        }
        void sub (Complex x) {
            a -= x.a;
            b -= x.b;
        }
        void mul (Complex x) {
            double buffer = (a * x.a) - (b * x.b);
            b = (a * x.b) + (b * x.a);
            a = buffer;
        }
        void div (Complex x) {
            double buffer = ((a * x.a) + (b * x.b)) / ((x.a * x.a) + (x.b * x.b));
            b = ((b * x.a) - (a * x.b)) / ((x.a * x.a) + (x.b * x.b));
            a = buffer;
        }
        bool equ (Complex x) {
            if ((a == x.a) && (b == x.b)) {
                return true;
            }
            else {
                return false;
            }
        }
        Complex conj () {
            return (Complex (a, - b));
        }
        bool com (Complex x) {
            double moduleFirst = sqrt (pow (a, 2) + pow (b, 2));
            double moduleSecond = sqrt (pow (x.a, 2) + pow (x.b, 2));
            return (moduleFirst == moduleSecond);
        }
        ~Complex () {}
    private:
        double a;
        double b;
};

Complex operator+ (Complex first, Complex second) {
    first.add (second);
    return first;
}

Complex operator- (Complex first, Complex second) {
    first.sub (second);
    return first;
}

Complex operator* (Complex first, Complex second) {
    first.mul (second);
    return first;
}

Complex operator/ (Complex first, Complex second) {
    first.div (second);
    return first;
}

bool operator== (Complex first, Complex second) {
    return (first.equ (second));
}

int main () {
    int option = 0;
    double real = 0;
    double imaginary = 0;
    Complex first;
    Complex second;
    Complex third;
    bool firstFlag = false;
    bool secondFlag = false;
    std::cout << "Menu:" << std::endl;
    std::cout << "0. Print menu." << std::endl;
    std::cout << "1. Enter the first complex number." << std::endl;
    std::cout << "2. Enter the second complex number." << std::endl;
    std::cout << "3. Print the first and second numbers." << std::endl;
    std::cout << "4. Addition of the first and second numbers." << std::endl;
    std::cout << "5. Subtract the second number from the first." << std::endl;
    std::cout << "6. Multiply the first number by the second." << std::endl;
    std::cout << "7. Divide the first number by the second." << std::endl;
    std::cout << "8. Compare the first number with the second." << std::endl;
    std::cout << "9. Print the conjugate of the first number." << std::endl;
    std::cout << "10. Compare the modules of the first and second numbers." << std::endl;
    std::cout << "11. Quit the program." << std::endl;
    while (option != 11) {
        std::cout << "Choose option: ";
        std::cin >> option;
        switch (option) {
            case 0: {
                std::cout << "Menu:" << std::endl;
                std::cout << "0. Print menu." << std::endl;
                std::cout << "1. Enter the first complex number." << std::endl;
                std::cout << "2. Enter the second complex number." << std::endl;
                std::cout << "3. Print the first and second numbers." << std::endl;
                std::cout << "4. Addition of the first and second numbers." << std::endl;
                std::cout << "5. Subtract the second number from the first." << std::endl;
                std::cout << "6. Multiply the first number by the second." << std::endl;
                std::cout << "7. Divide the first number by the second." << std::endl;
                std::cout << "8. Compare the first number with the second." << std::endl;
                std::cout << "9. Print the conjugate of the first number." << std::endl;
                std::cout << "10. Compare the modules of the first and second numbers." << std::endl;
                std::cout << "11. Quit the program." << std::endl;
                break;
            }
            case 1: {
                std::cout << "Enter real part: ";
                std::cin >> real;
                std::cout << "Enter imaginary part: ";
                std::cin >> imaginary;
                first.set (real, imaginary);
                firstFlag = true;
                break;
            }
            case 2: {
                std::cout << "Enter real part: ";
                std::cin >> real;
                std::cout << "Enter imaginary part: ";
                std::cin >> imaginary;
                second.set (real, imaginary);
                secondFlag = true;
                break;
            }
            case 3: {
                if (firstFlag) {
                    std::cout << "First number: (" << first.getRe () << ", " << first.getIm () << ")." << std::endl;
                }
                else {
                    std::cout << "Error: first number not entered." << std::endl;
                }
                if (secondFlag) {
                    std::cout << "Second number: (" << second.getRe () << ", " << second.getIm () << ")." << std::endl;
                }
                else {
                    std::cout << "Error: second number not entered." << std::endl;
                }
                break;
            }
            case 4: {
                if (firstFlag && secondFlag) {
                    third = first + second;
                    std::cout << "Result: (" << third.getRe () << ", " << third.getIm () << ")." << std::endl;
                }
                else {
                    if (!firstFlag) {
                        std::cout << "Error: first number not entered." << std::endl;
                    }
                    if (!secondFlag) {
                        std::cout << "Error: second number not entered." << std::endl;
                    }
                }
                break;
            }
            case 5: {
                if (firstFlag && secondFlag) {
                    third = first - second;
                    std::cout << "Result: (" << third.getRe () << ", " << third.getIm () << ")." << std::endl;
                }
                else {
                    if (!firstFlag) {
                        std::cout << "Error: first number not entered." << std::endl;
                    }
                    if (!secondFlag) {
                        std::cout << "Error: second number not entered." << std::endl;
                    }
                }
                break;
            }
            case 6: {
                if (firstFlag && secondFlag) {
                    third = first * second;
                    std::cout << "Result: (" << third.getRe () << ", " << third.getIm () << ")." << std::endl;
                }
                else {
                    if (!firstFlag) {
                        std::cout << "Error: first number not entered." << std::endl;
                    }
                    if (!secondFlag) {
                        std::cout << "Error: second number not entered." << std::endl;
                    }
                }
                break;
            }
            case 7: {
                if (firstFlag && secondFlag) {
                    if ((pow (second.getRe (), 2) + pow (second.getIm (), 2)) != 0) {
                        third = first / second;
                        std::cout << "Result: (" << third.getRe () << ", " << third.getIm () << ")." << std::endl;
                    }
                    else {
                        std::cout << "Error: division by zero." << std::endl;
                    }
                }
                else {
                    if (!firstFlag) {
                        std::cout << "Error: first number not entered." << std::endl;
                    }
                    if (!secondFlag) {
                        std::cout << "Error: second number not entered." << std::endl;
                    }
                }
                break;
            }
            case 8: {
                if (firstFlag && secondFlag) {
                    if (first == second) {
                        std::cout << "Numbers are equal." << std::endl;
                    }
                    else {
                        std::cout << "Numbers are not equal." << std::endl;
                    }
                }
                else {
                    if (!firstFlag) {
                        std::cout << "Error: first number not entered." << std::endl;
                    }
                    if (!secondFlag) {
                        std::cout << "Error: second number not entered." << std::endl;
                    }
                }
                break;
            }
            case 9: {
                if (firstFlag) {
                    third = first.conj ();
                    std::cout << "Result: (" << third.getRe () << ", " << third.getIm () << ")." << std::endl;
                }
                else {
                    std::cout << "Error: first number not entered." << std::endl;
                }
                break;
            }
            case 10: {
                if (firstFlag && secondFlag) {
                    if (first.com (second)) {
                        std::cout << "Numbers are equal in absolute value." << std::endl;
                    }
                    else {
                        std::cout << "Numbers are not equal in absolute value." << std::endl;
                    }
                }
                else {
                    if (!firstFlag) {
                        std::cout << "Error: first number not entered." << std::endl;
                    }
                    if (!secondFlag) {
                        std::cout << "Error: second number not entered." << std::endl;
                    }
                }
                break;
            }
            case 11: {
                break;
            }
            default: {
                std::cout << "Error: incorrect input." << std::endl;
                break;
            }
        }
    }
    return 0;
}