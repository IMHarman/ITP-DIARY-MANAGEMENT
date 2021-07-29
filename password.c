int password()

{

    char pass[15]= {0},check[15]= {0},ch;

    FILE *fpp;

    int i=0,j;

    printf("\t\t::FOR SECURITY PURPOSE::\n");

    printf("\t\t::ONLY THREE TRIALS ARE ALLOWED::");

    for(j=0; j<3; j++)

    {

        i=0;

        printf("\n\n\t\tENTER THE PASSWORD:");

        pass[0]=getch();

        while(pass[i]!='\r')

        {

            if(pass[i]=='\b')

            {

                i--;

                printf("\b");

                printf(" ");

                printf("\b");

                pass[i]=getch();

            }

            else

            {

                printf("*");

                i++;

                pass[i]=getch();

            }

        }

        pass[i]='\0';

        fpp=fopen("SE","r");

        if (fpp==NULL)

        {

            printf("\n\n\t\tERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");

            getch();

            return 1;

        }

        else

            i=0;

        while(1)

        {

            ch=fgetc(fpp);

            if(ch==EOF)

            {

                check[i]='\0';

                break;

            }

            check[i]=ch-5;

            i++;

        }

        if(strcmp(pass,check)==0)

        {

            printf("\n\n\t\tACCESS GRANTED...\n");

            return 0;

        }

        else

        {

            printf("\n\n\t\tWRONG PASSWORD..\n\n\t\tACCESS DENIED...\n");

        }

    }

    printf("\n\n\t\t::YOU ENTERED WRONG PASSWORD::\n\t\t::YOU ARE NOT ALLOWED TO ACCESS ANY FILE::\n\n\t\t\t\t\t   PRESS ANY KEY TO GO BACK...");

    getch();

    return 1;

}

void editpassword()

{

    system("cls");

    printf("\n");

    char pass[15]= {0},confirm[15]= {0},ch;

    int choice,i,check;
    
    printf("\t\t\t\t*********************************************\n");
 
    printf("\t\t\t\t      WELCOME TO CHANGING PASSWORD MENU!");

    printf("\n\t\t\t\t*********************************************\n");

    FILE *fp;

    fp=fopen("SE","rb");

    if(fp==NULL)

    {

        fp=fopen("SE","wb");

        if(fp==NULL)

        {

            printf("SYSTEM ERROR...");

            getch();

            return ;

        }

        fclose(fp);

        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");

        getch();

    }

    fclose(fp);

    check=password();

    if(check==1)

    {

        return ;

    }

    do

    {

        if(check==0)

        {

            i=0;

            choice=0;

            printf("\n\n\t\tENTER THE NEW PASSWORD: ");

            fflush(stdin);

            pass[0]=getch();

            while(pass[i]!='\r')

            {

                if(pass[i]=='\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    pass[i]=getch();

                }

                else

                {

                    printf("*");

                    i++;

                    pass[i]=getch();

                }

            }

            pass[i]='\0';

            i=0;

            printf("\n\t\tCONFIRM PASSWORD: ");

            confirm[0]=getch();

            while(confirm[i]!='\r')

            {

                if(confirm[i]=='\b')

                {

                    i--;

                    printf("\b");

                    printf(" ");

                    printf("\b");

                    confirm[i]=getch();

                }

                else

                {

                    printf("*");

                    i++;

                    confirm[i]=getch();

                }

            }

            confirm[i]='\0';

            if(strcmp(pass,confirm)==0)

            {

                fp=fopen("SE","wb");

                if(fp==NULL)

                {

                    printf("\n\t\tSYSTEM ERROR");

                    getch();

                    return ;

                }

                i=0;

                while(pass[i]!='\0')

                {

                    ch=pass[i];

                    putc(ch+5,fp);

                    i++;

                }

                putc(EOF,fp);

                fclose(fp);

            }

            else

            {

                printf("\n\t\tTHE NEW PASSWORD DOES NOT MATCH.");

                choice=1;

            }

        }

    }
    while(choice==1);

    printf("\n\n\t\tPASSWORD CHANGED...\n\n\t\tPRESS ANY KEY TO GO BACK...");

    getch();

}