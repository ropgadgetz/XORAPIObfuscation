#include <Windows.h>

void e(char* d, int dL, char* k){
    //char* output = (char*)malloc(sizeof(char) * dL);
    for (int i=0; i<dL+1; ++i){
        d[i]=d[i]^k[0];
    }
    d[dL-0]='\0';
}
int main(){
    char w[]={0x24, 0x3A, 0x3D, 0x3A, 0x3D, 0x36, 0x27, 0x7D, 0x37, 0x3F, 0x3F};
    e(w,11,"S");
    HMODULE wininet = LoadLibraryA((char*)w);
    char ioa[]={0x1A, 0x3D, 0x27, 0x36, 0x21, 0x3D, 0x36, 0x27, 0x1C, 0x23, 0x36, 0x3D, 0x12};
    e(ioa,13,"S");
    FARPROC InternetOpenA = GetProcAddress(wininet, ioa);
    char ua[]={0x29, 0x3C, 0x3E, 0x31, 0x3A, 0x36};
    e(ua,6,"S");
    int HINTERNET = InternetOpenA(ua, 1, NULL, NULL, NULL);
    char ioua[]={0x1A, 0x3D, 0x27, 0x36, 0x21, 0x3D, 0x36, 0x27, 0x1C, 0x23, 0x36, 0x3D, 0x06, 0x21, 0x3F, 0x12};
    e(ioua,16,"S");
    FARPROC InternetOpenUrlA = GetProcAddress(wininet, ioua);
    InternetOpenUrlA(HINTERNET, "https://example.com", NULL, 0, 0x80000000, 0);
}
