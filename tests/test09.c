#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum delimiters {
    DOUBLE_QUOTE = '"',
    WHITESPACE = ' '
};

enum status {
    MNS_ERROR = -1,
    ALL_FINE = 1
};

int mns_tknlen(char *line, int *tkn_len) {
    int in_quote = 0;
    int i = 0;
    while (line[i]) {
        if (line[i] == DOUBLE_QUOTE)
            in_quote = !in_quote;
        else if (!in_quote && line[i] == WHITESPACE) {
            i++;
            if(!line[i] || line[i] == WHITESPACE)
                continue;
            return i;
        }
        else
            (*tkn_len)++;
        i++;
    }
    return i;
}

char *mns_tkndup(char *line, int tkn_len, int position)
{
    char *token;
	int in_quote;
	int i;
	int	j;

	token = malloc(tkn_len + 1);
    if (!token)
		return (NULL);
    in_quote = 0;
   	i = 0;
	j = 0;
    while (line[i] && i < position)
	{
        if (line[i] == DOUBLE_QUOTE)
            in_quote = !in_quote;
        else if (!in_quote && line[i] == WHITESPACE)
		{
            i++;
            if (!line[i] || line[i] == WHITESPACE)
                continue ;
        }
        else if (j < tkn_len)
            token[j++] = line[i];
        i++;
    }
    token[j] = '\0';
    return (token);
}

int mns_split_process(char **splitted, char *line, int tokens)
{
    int i;
	int tkn_len;
	int position;

	i = 0;
    while (i < tokens)
	{
        tkn_len = 0;
        position = mns_tknlen(line, &tkn_len);
        splitted[i] = mns_tkndup(line, tkn_len, position);
        if (!splitted[i])
			return (MNS_ERROR);
        line += position;
        i++;
    }
    return ALL_FINE;
}

int mns_count_tokens(const char *line)
{
    int i;
	int	count;
	int	in_quote;

	i = 0;
	count = 1;
	in_quote = 0;
    while (line[i]) {
        if (line[i] == DOUBLE_QUOTE)
            in_quote = !in_quote;
        else if (!in_quote && line[i] == WHITESPACE)
		{
            if (!line[++i] || line[i] == WHITESPACE)
                continue;
            count++;
        }
        i++;
    }
    return (count);
}

int mns_split(char ***splitted, char *line)
{
	int tokens;
    while (*line == WHITESPACE)
		line++;
    tokens = mns_count_tokens(line);
    if (tokens == 0)
		return 0;
    *splitted = malloc((tokens + 1) * sizeof(char *));
    if (!*splitted)
		return (MNS_ERROR);
    if (mns_split_process(*splitted, line, tokens) == MNS_ERROR)
        return (MNS_ERROR);
    return (tokens);
}

int main() {
    char line[] = "\"\"123";
    char **splitted;
    int count = mns_split(&splitted, line);

    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, splitted[i]);
        free(splitted[i]);  // Don't forget to free individual strings
    }
    free(splitted);  // And the main array

    return 0;
}
