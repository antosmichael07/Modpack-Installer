#include <stdio.h>
#include <stdlib.h>

int charArrayLength();

int main() {

    char installOption[1024];
    char directory[1024];
    char cdCommand[1024] = "cd ";

    printf("Where do you want to install the mods?\n   A - Default minecraft directory\n   B - This directory\n   C - Custom directory\nExit - Enter anything else to exit\n");
    scanf("%s", &installOption);

    if (charArrayLength(installOption, sizeof(installOption)) > 1) {
        return 0;
    } else if (installOption[0] == 'A' || installOption[0] == 'a') {
        char temp[1024] = "\%APPDATA\%\\.minecraft";

        for (int i = 0; i < 20; i++) {
            directory[i] = temp[i];
        }
    } else if (installOption[0] == 'B' || installOption[0] == 'b') {
        directory[0] = ' ';
    } else if (installOption[0] == 'C' || installOption[0] == 'c') {
        scanf("%s", &directory);
    } else {
        return 0;
    } 

    for (int i = 0; i < charArrayLength(directory, sizeof(directory)); i++) {
        cdCommand[i + 3] = directory[i];
    }

    system(cdCommand);
    system("mkdir mods");
    system("cd mods");
    system("powershell");
    system("Invoke-WebRequest -Uri \"https://maven.minecraftforge.net/net/minecraftforge/forge/1.19.2-43.3.2/forge-1.19.2-43.3.2-installer.jar\" -OutFile \"forge-1.19.2-43.3.2-installer.jar\"");
    system("exit");
    system("start \"forge-1.19.2-43.3.2-installer.jar\"");

    return 0;
}

int charArrayLength(char array[], int arrayLength) {

    int temp = 0;

    for (int i = 0; i < arrayLength; i++) {
        if (array[i] == '\0') {
            break;
        }

        temp++;
    }

    return temp;
}