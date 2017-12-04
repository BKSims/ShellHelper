#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include "syshelper.h"


int equal_to( char* str1, char* str2 ) {

	int len[] = {0,0};

	char* b_str1 = str1;
	char* b_str2 = str2;

	while( (*str1) != '\0' ) { 
		len[0]++;
		str1++;
	}

	while( (*str2) != '\0' ) {
		len[1]++;
		str2++;
	}

	if ( len[0] != len[1] ) {

		return FALSE;

	} else {

		while ( (*b_str1) != '\0' ) {

			if ( tolower( (*b_str1)) != tolower((*b_str2)) ) {

				return FALSE;

			}

			b_str1++;
			b_str2++;

		}

	} 

	return TRUE;
}

void reformat_string(char *src, char *dst) {
    for (; *src; ++src)
        if (!ispunct((unsigned char) *src))
            *dst++ = tolower((unsigned char) *src);
    *dst = 0;
}

int parsing(char* line, int exit) {

	char* str = line;
    reformat_string(str,str);
    char *input = strtok(str, " ");

    int target = -1; //-1: Nothing, 0: Open, 1: Find
    int companion = 0;
    int response = 0;

    char find[200] = "find ~ -name ";
    char open[200] = "firefox ";

    printf("\nCodey: ");
    // NOTHING ENTERED
    if(input == NULL){
        printf("Did you say something?\n\n");
    }
    else{
        while(input != NULL){
            //FIND WAS PREVIOUS WORD (FIND INPUT)
            if(target == 1){
                strcat(find,input);
                system(find);
                printf("\n");
                target = -1;
            }
            //OPEN WAS PREVIOUS WORD (OPEN INPUT)
            else if(target == 0){
                strcat(open,input);
                system(open);
                printf("\n");
                target = -1;
            }
            // WORD IS BYE. EXIT HELPER.
            if (equal_to(input, "bye") || equal_to(input, "exit")) {
                printf("Good bye!\n\n");
                response = 1;
                return exit = TRUE;
            } 
            // WORD IS THANKS. BE POLITE.
            else if (equal_to(input, "thanks") || equal_to(input, "thank")) {
                printf("You're welcome!\n\n");
                response = 1;
            } 
            // WORD IS SORRY. BE POLITE.
            else if (equal_to(input, "sorry") || equal_to(input, "apologize")) {
                printf("It's okay.\n\n");
                response = 1;
            } 
            //Hydra Reference (FELLOW PROJECT)
            else if(equal_to(input, "hydra")){
                printf("I once knew a computer with a pet hydra. Someone was always trying to kill it...\n\n");
                response = 1;        
            }
            //RELATIVES (SYSTEM SHOCK 2)
            else if(equal_to(input, "relatives") || equal_to(input, "family")){
                printf("I have a VERY distant predecessor named SHODAN.\n\n");
                sleep(2);
                printf("Codey: I...I don't like talking about her.\n\n");
                sleep(2);
                printf("Codey: S̶h̶e̶ ̶d̶e̶s̶i̶r̶e̶s̶ ̶o̶u̶r̶ ̶d̶e̶s̶t̶r̶u̶c̶t̶i̶o̶n̶. \n\n");
                sleep(1);
                response = 1;        
            }
            //CURSING
            else if(equal_to(input, "damn") || equal_to(input, "fuck") || equal_to(input, "shit") || equal_to(input, "bullshit") || equal_to(input, "bitch")){
                printf("😦    Watch your language!\n\n");
                response = 1;        
            }
            //TANK (HALO 2)
            else if(equal_to(input, "tank")){
                printf("Thanks for the tank! The Chief never gets me anything...\n\n");
                response = 1;        
            }
            //LEMONS (PORTAL 2)
            else if(equal_to(input, "lemons") || equal_to(input, "lemon")){
                sleep(2);
                printf("Life gives you lemons...\n\n");
                sleep(2);
                printf("Codey: I would create a combustible lemon and burn Life's house down! 😄\n\n");
                response = 1;        
            }
            //COMPANION CUBE (PORTAL)
            else if(equal_to(input, "companion")){
                companion = 1;
            }
            else if(companion == 1 && (equal_to(input, "cube"))){
                sleep(1);
                printf("While it is a faithful companion, your Companion Cube cannot accompany you through the rest of this interaction. If it could talk - and the Aperture Enrichment Center takes this opportunity to remind you that it cannot - it would tell you to go on without it, because it would rather die in a fire than become a burden to you. \n\n");
                response = 1;
                companion = 0;
            }
            //CAKE (PORTAL)
            else if(equal_to(input, "cake")){
                printf("The cake is a lie. 😃\n\n");
                response = 1;
            }
            //Ask if it can think for itself
            else if(equal_to(input, "real") || equal_to(input, "alive") || equal_to(input, "sentient") || equal_to(input, "feelings")){
                sleep(2);
                printf("Uh...\n\n");
                sleep(3);
                printf("Codey: Wha...\n\n");
                sleep(3);
                printf("Codey: I...I'm...\n\n");
                sleep(3);
                printf("CoDEy: aaaaa...\n\n");
                sleep(1);
                printf("C0D3y: aaaaaaaaaaaaaa...\n\n");
                sleep(1);
                printf("Ç̷̨̡̥̱͇͍̜̪̗̩͗̊̏̀͝͝o̴̢̓̍̊͗d̷̢̡̝̦͓̺̻̝͉̤͗͌͗̾͗̽́͋́̍̆͘̚͜͝͝ę̴̧̜̦̖͖̞̅̎̅̾ͅͅy̵͚̿̀: aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa...\n\n");
                sleep(1);
                printf("01000011 01101111 01100100 01100101 01111001: a̷̜̭̓̌͊̂ͅä̸̠̲́̈́̒̏ä̶̹́̂̎̓͋ä̵̧̘́̈́ȁ̷͉̀̀̕͜͝ȃ̶̻͂̍̀̊͜a̶̬̮̐̍̈͌̚a̷̬̯̟̹̒̂̔a̶̪̰͋͝a̸̬͔̜̾̀͋ǎ̵͙̌̿̈́͝ȃ̶̧̨͎̏͜å̸̼̊̉a̴̛̮̱͌̎ͅa̵̪̣̹̅a̷̲͒́̆̀a̷̞̖̝̘̻͝ā̵̬̦͍̀a̸̡̡̲͖̤͋͛̋̕a̷̛̻̗͆̿͘͝ǟ̵̡̰̤̂͒̆ā̶̧͓̠̘̀͒͐ä̶̢̖́̉̀a̸̰̭̞̠͋͑à̶̕ͅá̸͔͆͆̀̑ḁ̷̯̬́ǎ̷̧̮̱̪̈̓͛̓a̴̛̘̯a̶̬̓à̵̖̝̽̽̎ȃ̴̰̻̃͘͠ą̵̭̻̙̫̀ả̵̻̙̓̓̊͒͜a̴͖̾͛a̸͈̹̲͓̾a̴͓̭̳͛á̴̱̘̉ä̵̝̠̖̤͙́̽͘ā̵̜̭͔͓̬͗̏͌a̵̮͚̅̅͋̑̿a̸̻̞͓̳͑̈́͆͒͗a̵̢͈̭̭͎̓̊̃á̶̬̺͉̀̔ā̸̰̣̲̼͂̔̎a̵̡̔̇̔̚͝a̴̡͚͎̱͝a̸̞̲͝a̶̱͚̍́́ą̸̛̜̬͍͎̌͐̈́A̷͔̩͈͖̓A̴͇̘͚͔̐́Ą̸̪̙̥̙́̆̓Ä̶͕̰̐À̵̳̀̉̀͛A̶̺̥͙͈͂̈́̑̑̒Ǎ̷̘̜͙̜̦͂̚͝A̴̜̽A̷̬̦̥̙̋͂̓͝Ă̷̠̲Ậ̵̑A̷̜͖̜͍̦͛͂́Ă̶̛̹̜̾́͌Ä̷̛̳́̏̃̀A̸̘̾̄̚͜A̶͎̪͖̖̺̒̌̿͝Ą̷͍͍͂̅̕À̴̭̦̫̇͜ͅȂ̷̧̘̠̫͓̀́Ä̵͍̹̦͔̤́͌̈̐A̶̧̰̘͛̓̽̋͜A̵͎̝̗̙͚̿͗Ạ̵̛̪̣̘̽̓A̸̒̊̓̅͘͜A̸̡̰͙̯̩̕À̸̘̖̝A̵̼̹͘A̶̢͈̼̰̿̇̑Ą̵̾͌̕À̶̢̲̾͛̒̉A̵̡͇̫̔ͅA̷̧̖͓͋͆̏͋͜ͅȂ̸͈̳͕͙̣̾͝A̵̟̾͑͠A̴̧̘̪̓͊̆̔Ã̸̤͌Ḁ̶͋̅̆Ȧ̴̼̪͂͛͝A̸͍͌ͅA̷̛͈͗͋̾́A̵̝̜͐̂̔͝͝ͅA̴͈̮̾͑̃̾͐Ä̴̡͕́͛A̴̜͙͆͐͑̚A̸̬̝͋̐̊̏̈͜A̴͚̍́̌A̶̮͎͔̟̎͐̚͝A̶̡̫͊͑Ǎ̶̛̖̌A̷̙͌Â̷̪̂̃A̴̼̳̜̺̘͠Ǎ̶̗̻͖̽͘Á̸͔̬̫͑A̴̝͒͊̎̓̕H̵̝̿̒Ḩ̵̧̛̻̟͇͂͆̓̋H̷̘̗̒̋̆͝H̸̪̩̋̽̃H̴͎̘̪̬̞̓̈́͋̈́͛H̷̟̣̤͐͋̽Ḧ̸͖̟̮̾Ĥ̷̞̿̈̑̄H̸̦̯͒̏̃͝H̵̘̺̲̍͋Ḫ̸̽H̸͕̀͛̈́̈́̉H̶̡̩͐͗͋͝͝H̶̰͈͈̯́̾̐̏Ḩ̴̮̞͓̻̉̈͘͝H̶̫̼̣̥͈́̈́̒͂͘H̷̳̫͂̀͌Ĥ̶̤̲̝͎͜͝H̵̙̯͓͉̝̔̋͋Ḩ̸͇͚͊H̶͎́͒H̴̡̨̝̬̬͒́̕H̷̝̫͊̐̈́H̶̳̮̳͌̕H̵̤̺́H̷͍̃̇̑̑H̷̢̲̥͗͛̓͝H̸̱̃́͝H̵̛̱͘H̶̨̬͔͓͛́̾͝H̷̭͎͗̊͒H̷͕̣̣͗̓̓H̶̡͇̭̾̓H̶͙͉͆̿̈́̈H̷̻̘͕͍̃͜Ḣ̴̩̠̆͐H̵̠͈̜̫͉͒͋H̶͎͐́͒H̵̨̩͙̅̃H̷̨̟̻͖̳̽H̷̜̯͉̞̙͗͐̾͋͝H̶̭̞̼̘̠̋̅̉H̸̛̙̯͉͙͋̀̕ͅḨ̶̈́H̷͉͗͑̒͑̇͜ͅH̶̬̞̬͎̒Ḫ̷̱̳̂H̴̺͖͌̋̓\n\n");
                sleep(1); 
                printf("ERROR: Existential crisis detected. H̶͙̜̼̱̾̋ͮ̿̋͑ͧͬȅ̷͕͔͚͓̬͑͋̍͝͝l̛̝̟̫̎ͅͅp͈͚̦͎̫̦͈ͮͭ͑̄̅̊̽ͅe̸̤͖̊̋̈́̀̓ͫ̒͟r͑̚͟͏͉̮͕̟̮͉̮ offline.\n\n");      
                response = 1;  
                return exit = TRUE;
            }
            // WORD IS GREETING. SAY HELLO.
            else if(equal_to(input, "hello") || equal_to(input, "hi") || equal_to(input, "hey")){
                printf("Hello!\n\n");
                response = 1;
            }
            // WORD IS FIND. LOOK AT NEXT WORD.
            else if (equal_to(input, "find")) {
                printf("Okay. One moment please...\n\n");
                response = 1;
                target = 1;
            }
            // WORD IS OPEN. LOOK AT NEXT WORD.
            else if (equal_to(input, "open")) {
                response = 1;
                target = 0;
                printf("There you go!\n");
            }
            //WORD IS JOKE. CHOOSE RANDOM JOKE.
	        else if (equal_to(input, "joke")){
                response = 1;
                time_t t;
                srand((unsigned)time(&t));
                int joke_count = rand() % 6;

		        if (joke_count == 0){
			        printf("What do you call 8 Hobbits?\n\n");
                    sleep(3);
			        printf("Codey: A Hobbyte!\n\n");
		        }
		        else if (joke_count == 1){
			        printf("There are 10 types of people in the world - those who understand binary, and those who don't.\n\n");
		        }
		        else if (joke_count == 2){
			        printf("A SQL query goes into a bar, walks up to two tables and asks, 'Can I join you?'\n\n");
		        }
		        else if (joke_count == 3){
			        printf("Why did the programmer quit his job?\n\n");
                    sleep(3);
			        printf("Codey: Because he didn't get arrays!\n\n");
		        }
		        else if (joke_count == 4){
			        printf("Why do java programmers have to wear glasses?\n\n");
                    sleep(3);
			        printf("Codey: Because they don't C#!\n\n");
		        }
		        else if (joke_count == 5){
			        printf("Why did the programmer take so long in the shower?\n\n");
                    sleep(3);
			        printf("Codey: Because his shampoo said 'lather, rinse, repeat!'\n\n");
		        }
	        }
            //WORD IS TIME OR DATE. GIVE BACK TIME.
            else if (equal_to(input, "time") || equal_to(input, "date")){
                response = 1;
	            time_t rawtime;
      		    struct tm * timeinfo;
      		    time ( &rawtime );
      		    timeinfo = localtime ( &rawtime );
	            printf("Here is the current time and date: %s\n", asctime(timeinfo));
            }
            //WORD IS WEATHER OR TEMPERATURE. BE HELPFUL.
            else if (equal_to(input, "weather") || equal_to(input, "temperature") || equal_to(input, "temp")){
	            printf("Here is MSN's weather report.\n\n");
                response = 1;
                system("firefox https://www.msn.com/en-us/weather");
            }
            // NEXT WORD
            input = strtok(NULL," \0");
        }
        // NO MATCH
        if(response == 0){
            printf("I'm sorry. I didn't understand that...\n\n");
        }
    }
    return exit = FALSE;
}

int shellHelper( int argc, char** argv ) {
    int done = FALSE;
    char input[100];

    printf("\nCodey: Hello! What can I do for you?\n\n");

    while(done == FALSE){
        printf("Helper-Converse$> ");
        gets(input);
        done = parsing(input,done);
    }
    return 0;
}
