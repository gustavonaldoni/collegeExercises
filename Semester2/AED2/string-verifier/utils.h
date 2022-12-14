void StringCut(char *, char *, int, int);
void StringTrim(char *, char *);
void StringReplace(char *, char *, char *);

int SplitWordsAndPushIntoList(char *, ListLDE *, ListLDE *);
void checkBadWords(char *);
void BlurWord(char *);
void ToLower(char *);
bool ValidateLastChar(char);

void FormatResultString(char *, ListLDE, ListLDE);

void StringCut(char *string, char *result, int init, int end)
{
    int i, j;
    int resSize = end - init + 1;

    j = 0;
    for (i = 0; i < strlen(string) + 1; i++)
    {
        if (i >= init && i <= end)
        {
            result[j] = string[i];
            j++;
        }

        if (i == end + 1)
        {
            result[j] = '\0';
        }
    }
}

void StringTrim(char *string, char *result)
{
    int i;
    int init, end;

    init = 0;
    end = strlen(string) - 1;

    for (i = 0; i < strlen(string) + 1; i++)
    {
        if (string[i] == ' ')
            init++;
        else
            break;
    }

    for (i = strlen(string) - 1; i >= 0; i--)
    {
        if (string[i] == ' ')
            end--;
        else
            break;
    }

    StringCut(string, result, init, end);
}

void StringReplace(char *original, char *word, char *to)
{
    int i, j;
    int init, end;
    int counter;

    init = -1;
    end = -1;
    counter = 1;

    for (i = 0; i < strlen(original) - 1; i++)
    {
        if (original[i] == word[0] &&
                     (original[i - 1] == ' ' ||
                      original[i - 1] == '.' ||
                      original[i - 1] == '!' ||
                      original[i - 1] == ';' ||
                      original[i - 1] == ',') &&
                     (original[i + strlen(word)] == ' ' ||
                      original[i + strlen(word)] == '.' ||
                      original[i + strlen(word)] == '!' ||
                      original[i + strlen(word)] == ';' ||
                      original[i + strlen(word)] == ',') ||
                 (i == 0 &&
                  (original[i + strlen(word)] == ' ' ||
                   original[i + strlen(word)] == '.' ||
                   original[i + strlen(word)] == '!' ||
                   original[i + strlen(word)] == ';' ||
                   original[i + strlen(word)] == ',')))
        {
            init = i;

            for (j = 1; j < strlen(word); j++)
            {
                if (original[i + j] == word[j])
                {
                    counter++;
                }

                else
                {
                    counter = 1;
                    init = -1;
                    end = -1;
                    break;
                }
            }

            if (counter == strlen(word))
            {
                end = init + strlen(word) - 1;

                for (i = init; i <= end; i++)
                {
                    original[i] = to[i - init];
                }
            }
        }
    }
}

int SplitWordsAndPushIntoList(char *string, ListLDE *words, ListLDE *wordsTo)
{
    int i, k = 0, j, initWord = -1;
    char cop[256], t[256];

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == '.' || string[i] == ',' || string[i] == ':' || string[i] == ';' || string[i] == '?' || string[i] == '!')
            string[i] = ' ';
    }

    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ')
        {
            while (string[i + 1] == ' ')
            {
                i++;
            }

            strcpy(cop, "");
            for (j = initWord + 1; j < i; j++)
            {
                cop[k] = string[j];
                k++;
            }
            cop[k] = '\0';
            k = 0;
            initWord = i;

            StringTrim(cop, t);
            ListLDEInsertEnd(words, t);

            ToLower(t);
            checkBadWords(t);
            ListLDEInsertEnd(wordsTo, t);
        }
    }

    if (initWord == -1)
    {
        ListLDEInsertEnd(words, string);
    }
}

void checkBadWords(char *word)
{
    int i, j;
    bool verify = false;

    char badWordsPortuguese[91][20] = {"abestado", "arrombado", "babaca", "boquete", "bixa", "bicha",
                                       "besta", "bosta", "buceta", "baitola", "bunda", "boiola", "benga",
                                       "boceta", "cacete", "caralho", "cu", "cusao", "cuzao", "chota", "cagar", "cretino", "chupar",
                                       "corno", "corna", "cornudo", "desgracado", "desgra??ado", "desgracada", "froxo", "gozar", "debil",
                                       "desgra??ada", "energumeno", "estupido", "foda", "fudido", "foder", "foda-se", "fuder", "garalho", "idiota", "imbecil", "merda", "mijar", "otario", "ot??rio",
                                       "rola", "roludo", "roluda", "rabao", "rabuda", "rabudo", "porra",
                                       "puta", "putinha", "putinho", "poha", "pal", "palzao", "palsao", "piroca", "pau", "pausao",
                                       "pika", "pica", "punhetao", "punheta", "piru", "pausudo",
                                       "palzudo", "pikao", "picao", "troxa", "trouxa", "tcheca", "vadia", "viado", "vagabundo", "viadinho", "viadao", "xota", "xotao",
                                       "xeca", "xequinha",
                                       "tnc", "vtnc", "pqp", "k7", "kct"};

    char badWordsEnglish[34][20] = {"ass", "asshole", "bastard", "bullshit", "bitch", "blowjob",
                                    "crap", "cunt", "cock", "cuck", "cuckold", "cum",
                                    "dumbass", "damn", "dick", "fap", "faggot", "fuck",
                                    "fucker", "fucked", "hell", "hoe", "incell",
                                    "motherfucker", "motherfuck", "nigga", "nigger",
                                    "pee", "piss", "pussy", "shit", "sucker", "slut", "whore"};

    char badWordsSpanish[18][20] = {"boludo", "carajo", "carajo",
                                    "cabron", "cornudo", "cuerno", "chupamedias", "cagon",
                                    "despelote", "gilipollas", "huevon", "lata", "pelotudo",
                                    "puta", "pesado", "pelma", "pajero", "putear"};

    char badWordsFrench[41][20] = {"abruti", "andouille", "b??te", "bete", "boulet", "bougre",
                                   "bouffon", "con", "conne", "chier", "connasse",
                                   "chiant", "chiante", "cul", "casse-toi", "couilles", "chienne", "degage", "d??bile", "debile"
                                                                                                                       "d??gage",
                                   "encul??", "encule", "emmanche", "emmanch??",
                                   "encull??", "enculle", "emmerdeur", "fumier", "imb??cile", "imbecile",
                                   "m???emmerder", "m??re", "mere", "pute", "p??d??", "p??de", "ped??", "t???emmerde", "salopard", "stupide"};

    char badWordsItalian[19][20] = {"bagascia", "cazzo", "culo", "cagare",
                                    "cacare", "coglioni", "ditalino", "froscio", "inculata", "minhcia",
                                    "palla", "pippa", "pugneta", "pazzo", "pompino"
                                                                          "puttana",
                                    "stronzo", "sborra", "vafancullo"};

    for (i = 0; i < 91; i++)
    {
        if (strcmp(badWordsPortuguese[i], word) == 0)
            verify = true;
    }

    for (i = 0; i < 34; i++)
    {
        if (strcmp(badWordsEnglish[i], word) == 0)
            verify = true;
    }

    for (i = 0; i < 18; i++)
    {
        if (strcmp(badWordsSpanish[i], word) == 0)
            verify = true;
    }

    for (i = 0; i < 41; i++)
    {
        if (strcmp(badWordsFrench[i], word) == 0)
            verify = true;
    }

    for (i = 0; i < 19; i++)
    {
        if (strcmp(badWordsFrench[i], word) == 0)
            verify = true;
    }

    if (verify)
    {
        BlurWord(word);
        return;
    }
}

void BlurWord(char *word)
{
    int i;

    for (i = 0; i < strlen(word); i++)
    {
        word[i] = '*';
    }
}

void ToLower(char *word)
{
    int i;

    for (i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }
}

void FormatResultString(char *string, ListLDE words, ListLDE wordsTo)
{
    struct Node *aux1, *aux2;

    if (ListLDEIsEmpty(words) && ListLDEIsEmpty(wordsTo))
        return;

    aux1 = words.init;
    aux2 = wordsTo.init;

    while (aux1 != NULL && aux2 != NULL)
    {
        StringReplace(string, aux1->text, aux2->text);
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
}
