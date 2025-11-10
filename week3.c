int evaluatepostfixExp(char exp[])
{
    int i = 0, op1, op2, value;

    while (exp[i] != '\0' && exp[i] != '\n')
    {
        if (isdigit(exp[i]))
        {
            int digit = exp[i] - '0';
            push(st, digit);
        }
        else if (exp[i] == ' ' || exp[i] == '\t')
        {
            // Ignore spaces and tabs
        }
        else // must be an operator
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
                case '%':
                    value = op1 % op2;
                    break;
                default:
                    printf("\nInvalid operator: %c\n", exp[i]);
                    return 0;
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}

