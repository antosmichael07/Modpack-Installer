#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char installOption[1024];
    char javaInstallOption[1024];
    char directory[1024];

    printf("%s", "Where do you want to install the mods?\n   A - Default minecraft directory ( \%APPDATA\% -> .minecraft )\n   B - This directory\n   C - Custom directory ( It has to be already made )\nExit - Enter anything else to exit\n");
    scanf("%s", &installOption);

    if (strlen(installOption) > 1) {
        return 0;
    } else if (installOption[0] == 'A' || installOption[0] == 'a') {
        strcat(directory, "\%APPDATA\%\\.minecraft");
    } else if (installOption[0] == 'B' || installOption[0] == 'b') {
        directory[0] = ' ';
    } else if (installOption[0] == 'C' || installOption[0] == 'c') {
        scanf("%s", &directory);
    } else {
        return 0;
    } 

    printf("Do you have java installed?\nY - Yes\nN - No\n");
    scanf("%s", &javaInstallOption);

    if (strlen(javaInstallOption) > 1) {
        return 0;
    } else if (javaInstallOption[0] == 'Y' || javaInstallOption[0] == 'y') {
        printf("");
    } else if (javaInstallOption[0] == 'N' || javaInstallOption[0] == 'n') {
        printf("");
    } else {
        return 0;
    }

    char batFileDestination[1024] = "";
    strcat(batFileDestination, directory);
    strcat(batFileDestination, "\\mods\\downloader.bat");

    char cmdCommand1[1024] = "echo powershell >> ";
    strcat(cmdCommand1, batFileDestination);
    system(cmdCommand1);

    char cmdCommand2[1024] = "echo Invoke-WebRequest -Uri \"https://www.dropbox.com/scl/fi/mkldyx7lv90scoowxd839/mods.zip?rlkey=8hd42awzi5szq96aovb8ocu6r&dl=1\" OutFile \"mods.zip\" >> ";
    strcat(cmdCommand2, batFileDestination);
    system(cmdCommand2);

    char cmdCommand3[1024] = "echo exit >> ";
    strcat(cmdCommand3, batFileDestination);
    system(cmdCommand3);

    char cmdCommand4[1024] = "echo tar -xf mods.zip >> ";
    strcat(cmdCommand4, batFileDestination);
    system(cmdCommand4);

    char cmdCommand5[1024] = "start ";
    strcat(cmdCommand5, batFileDestination);
    system(cmdCommand5);

    return 0;
}