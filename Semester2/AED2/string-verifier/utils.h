void StringCut(char *, char *, int, int);
void StringTrim(char *, char *);
int SplitWordsAndPushIntoList(char *, ListLDE *);
void checkBadWords(char *);
void BlurWord(char *);
void ToLower(char *);
bool ValidateLastChar(char);

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

int SplitWordsAndPushIntoList(char *string, ListLDE *list)
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
            ToLower(t);
            checkBadWords(t);
            ListLDEInsertEnd(list, t);
        }
    }

    if (initWord == -1)
    {
        ListLDEInsertEnd(list, string);
    }
}

void checkBadWords(char *word)
{
    int i, j;
    bool verify = false;

    char badWordsPortuguese[91][20] = {"abestado", "arrombado", "babaca", "boquete", "bixa", "bicha",
                                       "besta", "bosta", "buceta", "baitola", "bunda", "boiola", "benga",
                                       "boceta", "cacete", "caralho", "cu", "cusao", "cuzao", "chota", "cagar", "cretino", "chupar",
                                       "corno", "corna", "cornudo", "desgracado", "desgraçado", "desgracada", "froxo", "gozar", "debil",
                                       "desgraçada", "energumeno", "estupido", "foda", "fudido", "foder", "foda-se", "fuder", "garalho", "idiota", "imbecil", "merda", "mijar", "otario", "otário",
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

    char badWordsFrench[41][20] = {"abruti", "andouille", "bête", "bete", "boulet", "bougre",
                                   "bouffon", "con", "conne", "chier", "connasse",
                                   "chiant", "chiante", "cul", "casse-toi", "couilles", "chienne", "degage", "débile", "debile"
                                                                                                                       "dégage",
                                   "enculé", "encule", "emmanche", "emmanché",
                                   "encullé", "enculle", "emmerdeur", "fumier", "imbécile", "imbecile",
                                   "m’emmerder", "mère", "mere", "pute", "pédé", "péde", "pedé", "t’emmerde", "salopard", "stupide"};

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
        word[i] = 'X';
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
