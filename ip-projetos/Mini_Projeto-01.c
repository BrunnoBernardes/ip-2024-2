#include <stdio.h>
#include <math.h>

int main()
{
    double const1, const2, result;
    char op;
    int const1_int, const2_int, result_int;

    scanf("%lf%c%lf", &const1, &op, &const2);

    const1_int = const1;
    const2_int = const2;

    if (const1 != const1_int || const2 != const2_int)
    {
        switch (op)
        {
        case '+':
            result = const1 + const2;
            printf("%g", result);
            break;
        case '-':
            result = const1 - const2;
            printf("%g", result);
            break;
        case '*':
            result = const1 * const2;
            printf("%g", result);
            break;
        case '/':
            result = const1 / const2;
            printf("%g", result);
            break;
        case '~':
            result = pow(const1, const2);
            printf("%g", result);
            break;
        case '=':
            if (const1 == const2)
                printf("true");
            else
                printf("false");
            break;
        case '!':
            if (const1 != const2)
                printf("true");
            else
                printf("false");
            break;
        case '<':
            if (const1 < const2)
                printf("true");
            else
                printf("false");
            break;
        case '>':
            if (const1 > const2)
                printf("true");
            else
                printf("false");
            break;

        default:
            break;
        }
    }
    else
    {
        switch (op)
        {
        case '+':
            result_int = const1_int + const2_int;
            printf("%d", result_int);
            break;
        case '-':
            result_int = const1_int - const2_int;
            printf("%d", result_int);
            break;
        case '*':
            result_int = const1_int * const2_int;
            printf("%d", result_int);
            break;
        case '/':
            if (const1_int % const2_int == 0)
            {
                result_int = const1_int / const2_int;
                printf("%d", result_int);
            }
            else
            {
                result = const1 / const2;
                printf("%g", result);
            }
            break;
        case '%':
            result_int = const1_int % const2_int;
            printf("%d", result_int);
            break;
        case '~':
            result_int = pow(const1_int, const2_int);
            printf("%d", result_int);
            break;
        case '=':
            if (const1_int == const2_int)
                printf("true");
            else
                printf("false");
            break;
        case '!':
            if (const1_int != const2_int)
                printf("true");
            else
                printf("false");
            break;
        case '<':
            if (const1_int < const2_int)
                printf("true");
            else
                printf("false");
            break;
        case '>':
            if (const1_int > const2_int)
                printf("true");
            else
                printf("false");
            break;
        case '^':
            if ((const1_int == 1 || const1_int == 0) && (const2_int == 1 || const2_int == 0))
            {
                if (const1_int == 1 && const2_int == 1)
                    printf("true");
                else
                    printf("false");
            }
            break;
        case 'v':
            if ((const1_int == 1 || const1_int == 0) && (const2_int == 1 || const2_int == 0))
            {
                if (const1_int == 0 && const2_int == 0)
                    printf("false");
                else
                    printf("true");
            }
            break;
        case 'x':
            if ((const1_int == 1 || const1_int == 0) && (const2_int == 1 || const2_int == 0))
            {
                if (const1_int == 1 && const2_int == 0)
                    printf("true");
                else if (const1_int == 0 && const2_int == 1)
                    printf("true");
                else
                    printf("false");
            }
            break;

        default:
            break;
        }
    }
    return 0;
}