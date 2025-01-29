//Adding some comments
//Just more comments
char* RLE(char* input) {
    char* output = malloc(2 * strlen(input) + 1);
    int k = 0;
    int out_put_index = 0;
    while (input[k] != '\0')
    {
        char current = input[k];
        int counter = 1;

        while (input[k + 1] != '\0' && current == input[k + 1])
        {
            k++;
            counter++;
        }
        out_put_index += sprintf(&output[out_put_index], "%d%c", counter, current);
        k++;
    }
    sprintf(&output[out_put_index], "\0");
    return output;
}

int counter_of_global;

char* countAndSay(int n) {
    char*result = malloc(sizeof(int)+1);
    result[0] = '1';
    result[1] = '\0';
    for (int i = 1; i < n; i++)
    {
        result = RLE(result);
    }
    return result;
}
