/*  Application MIROIR  : cote serveur      */

#include "commun.h"


void miroir (char *chaine);
int getAvaliablePort(unsigned short *port);

int main (int argc, char **argv)
{

    /*---------------------------------------------- les variables */
    /* pour le serveur */
    struct sockaddr_in adTCP_serveur;   /* pour mettre l'adresse de son point d'accès */
    int point_acces_serveur, guichet, guichet2;
    unsigned short port;

    /* pour le service */
    struct sockaddr_in adresse_appelant, adresse_appelant2;
#ifdef  __osf__
    int lg_appelant;
#else
    socklen_t lg_appelant;
#endif
    char message[100];
    char message2[100];
    int recus, recus2, emis, emis2;

	int message_int, message2_int;

    /* divers */
    int retour;

    /*---------------------------------------------- l'algorithme */
    //aquerir le numero de la port automatiquement
    getAvaliablePort(&port);
    /* création d'un point d'accès */
    point_acces_serveur = socket (PF_INET, SOCK_STREAM, 0);
    if (point_acces_serveur < 0)
    {
        perror ("ERREUR-socket ");
        exit (-1);
    }
    /* préparation de l'adresse du point d'accès */
    bzero (&adTCP_serveur, sizeof (adTCP_serveur));
    adTCP_serveur.sin_family = AF_INET;
    adTCP_serveur.sin_port = htons (port);
    adTCP_serveur.sin_addr.s_addr = INADDR_ANY;

    /* attribution de l'adresse au point d'accès */
    retour = bind (point_acces_serveur,
               (struct sockaddr *) &adTCP_serveur,
               sizeof (struct sockaddr_in));
    if (retour < 0)
    {
        perror ("ERREUR-bind ");
        exit (-1);
    }
    /* déclaration de répondeur */
    retour = listen (point_acces_serveur, 5);

    printIP(); //affiche l'adresse IP du serveur
    printf ("port:%d\n", port);

    if (retour < 0)
    {
        perror ("ERREUR-listen ");
        close (point_acces_serveur);
        exit (1);
    }


/* attente et traitement d'une demande */

    /* attente d'un appel */
    lg_appelant = sizeof (struct sockaddr_in);
    guichet = accept (point_acces_serveur,
              (struct sockaddr *) &adresse_appelant,
              &lg_appelant);
    guichet2 = accept (point_acces_serveur,
              (struct sockaddr *) &adresse_appelant2,
              &lg_appelant);

    if (guichet < 0 || guichet2 < 0)
    {
        perror ("ERREUR-accept() ");
    }
    printf ("---------------------CONNEXION de %s:%d\n",
        inet_ntoa (adresse_appelant.sin_addr),
        ntohs (adresse_appelant.sin_port));
    printf ("---------------------CONNEXION de %s:%d\n",
        inet_ntoa (adresse_appelant2.sin_addr),
        ntohs (adresse_appelant2.sin_port));



	//premiere communication choix des personnages

		recus  = recv (guichet, message, sizeof (message), 0);
	    recus2 = recv (guichet2, message2, sizeof (message2), 0);
	    if (recus < 0 || recus2 < 0)
	    {
	        perror ("ERREUR-recv ");
	        shutdown (guichet, SHUT_RDWR);
	        close (guichet);

	    }
	    else
	    {
	        printf ("RECU %d octets : ", recus);
	        printf ("\t%s\n", message);
	        printf ("RECU2 %d octets : ", recus2);
	        printf ("\t%s\n", message2);


	        if( strcmp(message, "fin") == 0 || strcmp(message2, "fin") == 0)
	        {
	        	sprintf(message, "fin");
	        	emis = send (guichet2, message, strlen (message) + 1, 0);
	        	emis2 = send (guichet, message, strlen (message) + 1, 0);

	        }

	        /* et on lui renvoie */
	        emis = send (guichet2, message, strlen (message) + 1, 0);
	        emis2 = send (guichet, message2, strlen (message2) + 1, 0);
	        if (emis < 0 || emis2<2)
	        {
	            perror ("ERREUR-send ");
	        }
	        else
	        {
	            printf ("ENVOI %d octets : ",emis);
	            printf ("\t%s\n", message);
	        }
		}



    while(1)
    {
    	// Entrer dans le jeu
    /* réception */
	    recus  = recv (guichet, &message_int, sizeof (message_int), 0);
	    recus2 = recv (guichet2, &message2_int, sizeof (message2_int), 0);
	    if (recus < 0 || recus2 < 0)
	    {
	        perror ("ERREUR-recv ");
	        shutdown (guichet, SHUT_RDWR);
	        close (guichet);
	        continue;
	    }
	    else
	    {
	        printf ("RECU %d octets : ", recus);
	        printf ("\t%d\n", message_int);
	        printf ("RECU2 %d octets : ", recus2);
	        printf ("\t%d\n", message2_int);


	        /* et on lui renvoie */
	        emis = send (guichet2, &message_int, sizeof(message_int), 0);
	        emis2 = send (guichet, &message2_int, sizeof(message2_int), 0);
	        if (emis < 0 || emis2<2)
	        {
	            perror ("ERREUR-send ");
	        }
	        else
	        {
	            printf ("ENVOI %d octets : ",emis);
	            printf ("\t%s\n", message);
	        }
	    }
	}
    printf ("---------------------FIN de CONNEXION de %s:%d\n",
        inet_ntoa (adresse_appelant.sin_addr),
        ntohs (adresse_appelant.sin_port));
    printf ("---------------------FIN de CONNEXION de %s:%d\n",
        inet_ntoa (adresse_appelant2.sin_addr),
        ntohs (adresse_appelant2.sin_port));
    shutdown (guichet, SHUT_RDWR);
    shutdown (guichet2, SHUT_RDWR);
    close (guichet);
    close (guichet2);

    close (point_acces_serveur);
}










typedef int SOCKET;
typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
#define closesocket(s) close(s)

// Cette fonction c'est pour aquerir le numero de la port automatiquement
int getAvaliablePort(unsigned short *port)
{
    int result = 1;


    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. 创建一个sockaddr，并将它的端口号设为0
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = 0;        // 若port指定为0,则调用bind时，系统会为其指定一个可用的端口号

    int ret = bind(sock, (SOCKADDR*)&addr, sizeof addr);

    if (0 != ret) {
        result = -1;
        return -1;
    }

    // 利用getsockname获取
    struct sockaddr_in connAddr;
    unsigned int len = sizeof connAddr;
    ret = getsockname(sock, (SOCKADDR*)&connAddr, &len);

    if (0 != ret){
        result = -1;
        return -1;
    }

    *port = ntohs(connAddr.sin_port); // 获取端口号

    if ( 0 != closesocket(sock) )
        result = -1;
    return result;
}

void printIP()
{
    char s[256];

    if (!gethostname(s, sizeof s))
    {
        printf ("Serveur: %s\n", s);
        {
            struct hostent *host= gethostbyname(s);

            if (host  != NULL)
            {
                struct in_addr **adr;

                for (adr = (struct in_addr **)host->h_addr_list; *adr; adr++)
                {
                    printf("IP : %s\n", inet_ntoa(**adr));
                }
            }
        }
    }
}
