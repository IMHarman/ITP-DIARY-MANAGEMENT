void deleterecord( )

{

    system("cls");

    FILE *fp,*fptr ;

    struct record file ;

    char filename[15],another = 'Y' ,time[10];;

    int choice,check;

    printf("\n\t\t\t\t*********************************************\n");
 
    printf("\t\t\t\t\t    WELCOME TO DELETE MENU!");

    printf("\n\t\t\t\t*********************************************\n");

    check = password();

    if(check==1)

    {

        return ;

    }

    while ( another == 'Y' )

    {

        printf("\n\n\t\tHOW WOULD YOU LIKE TO DELETE.");

        printf("\n\n\t\t#DELETE WHOLE RECORD\t\t\t[1]");

        printf("\n\t\t#DELETE A PARTICULAR RECORD BY TIME\t[2]");

        do

        {

            printf("\n\n\t\tENTER YOU CHOICE:");

            scanf("%d",&choice);

            switch(choice)

            {

            case 1:

                printf("\n\t\tENTER THE DATE OF RECORD TO BE DELETED:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "wb" ) ;

                if ( fp == NULL )

                {

                    printf("\n\t\tTHE FILE DOES NOT EXISTS");

                    printf("\n\t\tPRESS ANY KEY TO GO BACK.");

                    getch();

                    return ;

                }

                fclose(fp);

                remove(filename);

                printf("\n\t\tDELETED SUCCESFULLY...");

                break;

            case 2:

                printf("\n\t\tENTER THE DATE OF RECORD:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "rb" ) ;

                if ( fp == NULL )

                {

                    printf("\n\t\tTHE FILE DOES NOT EXISTS");

                    printf("\n\t\tPRESS ANY KEY TO GO BACK.");

                    getch();

                    return ;

                }

                fptr=fopen("temp","wb");

                if(fptr==NULL)

                {

                    printf("\n\t\tSYSTEM ERROR");

                    printf("\n\t\tPRESS ANY KEY TO GO BACK");

                    getch();

                    return ;

                }

                printf("\n\t\tENTER THE TIME OF RECORD TO BE DELETED:[hh:mm]:");

                fflush(stdin);

                gets(time);

                while(fread(&file,sizeof(file),1,fp)==1)

                {

                    if(strcmp(file.time,time)!=0)

                        fwrite(&file,sizeof(file),1,fptr);

                }

                fclose(fp);

                fclose(fptr);

                remove(filename);

                rename("temp",filename);

                printf("\n\t\tDELETED SUCCESFULLY...");

                break;

            default:

                printf("\n\t\tYOU ENTERED WRONG CHOICE");

                break;

            }

        }
        while(choice<1||choice>2);

        printf("\n\t\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");

        fflush(stdin);

        scanf("%c",&another);

    }

    printf("\n\n\t\tPRESS ANY KEY TO EXIT...");

    getch();

}
