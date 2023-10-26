#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char directory[1024] = "";
    char installOption[1024] = "";
    printf("%s", "Where do you want to install the mods?\n   A - Default minecraft directory ( \%APPDATA\% -> .minecraft ) ( Recommended for idiots )\n   B - Custom directory ( It has to be already made )\nExit - Enter anything else to exit\n");
    scanf("%s", &installOption);
    if (strlen(installOption) > 1) {
        return 0;
    } else if (installOption[0] == 'A' || installOption[0] == 'a') {
        strcat(directory, "\%APPDATA\%\\.minecraft");
    } else if (installOption[0] == 'B' || installOption[0] == 'b') {
        printf("Enter the directory\n");
        scanf("%s", &directory);
    } else {
        return 0;
    } 

    char batFileDestination[1024] = "\%TEMP\%\\mispul_create_survival\\mod_downloader.bat";

    system("mkdir \%TEMP\%\\mispul_create_survival");

    char cmdCommand1[1024] = "mkdir ";
    strcat(cmdCommand1, directory);
    strcat(cmdCommand1, "\\mods");
    system(cmdCommand1);

    char cmdCommand2[1024] = "echo cd ";
    strcat(cmdCommand2, directory);
    strcat(cmdCommand2, "\\mods >> ");
    strcat(cmdCommand2, batFileDestination);
    system(cmdCommand2);

    char cmdCommand3[1024] = "echo del /q * >> ";
    strcat(cmdCommand3, batFileDestination);
    system(cmdCommand3);

    char cmdCommand4[1024] = "echo cd \%TEMP\%\\mispul_create_survival >> ";
    strcat(cmdCommand4, batFileDestination);
    system(cmdCommand4);

    char cmdCommand5[1024] = "echo powershell -Command \"& {Invoke-WebRequest -Uri \\\"https://www.dropbox.com/scl/fi/2p7vrs1w7ks6se220z09i/mods.zip?rlkey=kb0284s88wvyfqjvspmf5y0p1\"&\"dl=1\\\" -OutFile \\\"mods.zip\\\"}\" >> ";
    strcat(cmdCommand5, batFileDestination);
    system(cmdCommand5);

    char cmdCommand6[1024] = "echo tar -xf mods.zip >> ";
    strcat(cmdCommand6, batFileDestination);
    system(cmdCommand6);

    char cmdCommand7[1024] = "echo copy \"*.jar\" \"";
    strcat(cmdCommand7, directory);
    strcat(cmdCommand7, "\\mods\" >> ");
    strcat(cmdCommand7, batFileDestination);
    system(cmdCommand7);

    char cmdCommand8[1024] = "echo del /q * >> ";
    strcat(cmdCommand8, batFileDestination);
    system(cmdCommand8);

    system(batFileDestination);

    printf("\n\n\n");

    char javaInstallOption[1024] = "";
    printf("Do you have java installed?\nY - Yes\nN - No\n");
    scanf("%s", &javaInstallOption);
    if (strlen(javaInstallOption) > 1) {
        return 0;
    } else if (javaInstallOption[0] == 'Y' || javaInstallOption[0] == 'y') {
        printf("");
    } else if (javaInstallOption[0] == 'N' || javaInstallOption[0] == 'n') {
        system("powershell -Command \"& {Invoke-WebRequest -Uri \\\"https://www.dropbox.com/scl/fi/0d6yljk1l9tlw29l13aiv/jdk-17_windows-x64_bin.exe?rlkey=rsag7q0wcpyoqbfuwerv4en4s\"&\"dl=1\\\" -OutFile \\\"\%TEMP\%\\mispul_create_survival\\jdk-17_windows-x64_bin.exe\\\"}\"");
        system("\%TEMP\%\\mispul_create_survival\\jdk-17_windows-x64_bin.exe");
        system("del /q \%TEMP\%\\mispul_create_survival\\*");
    } else {
        return 0;
    }

    printf("\n\n\n");

    printf("Installing forge...");

    system("echo cd \%TEMP\%\\mispul_create_survival >> \%TEMP\%\\mispul_create_survival\\forge_downloader.bat");
    system("echo powershell -Command \"& {Invoke-WebRequest -Uri \\\"https://www.dropbox.com/scl/fi/457u3io80ww453kfp5m0w/forge-1.19.2-43.3.2-installer.jar?rlkey=h8177jq7cklxgtg08fb7nanbo\"&\"dl=1\\\" -OutFile \\\"forge-1.19.2-43.3.2-installer.jar\\\"}\" >> \%TEMP\%\\mispul_create_survival\\forge_downloader.bat");
    system("echo java -jar forge-1.19.2-43.3.2-installer.jar >> \%TEMP\%\\mispul_create_survival\\forge_downloader.bat");
    system("\%TEMP\%\\mispul_create_survival\\forge_downloader.bat");
    system("del /q \%TEMP\%\\mispul_create_survival\\*");

    system("rmdir \%TEMP\%\\mispul_create_survival");

    printf("\n");
    
    system("pause");

    return 0;
}