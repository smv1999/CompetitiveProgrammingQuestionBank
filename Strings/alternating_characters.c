int alternatingCharacters(String s) {
    int a=strlen(s);
    int k=0,i;
    for(i=0;i<a;i++)
    {
        if(s[i]==s[i+1])
            k++;
    }
    return k;
}
