/*
lsmmr.c - to make secure deletion for a file

author : Yoghaswara Hadi Nugroho (cymdle33)

Description :
lsmmr is tool for secure deletion , secure move , duplicate files.

algorithm for deletion :

- read buffer
- overwritten buffer
- remove the file


[ features ]
* secure move method

Library use : C linux

thanks for :

colin plumb ( nice concept )

n.k ( for the tear )

*/
// use read dir for get the all name at once in directory
#include "lsmmr.h"

int initgraph(){
	printf("lsmmr , written by: lapua92");
	printf("-- Privacy is right too --");
}

int ovwrt_buf(string pathsrc,int verb){
	FILE *fsrc;// pointer
	int sizebuff;
	string a;
	unsigned int mask 0xff000000 // set zero buffers
	fsrc = open(pathsrc,O_WRONLY|O_TRUNC|,S_IWUSR|S_IRUSR);
	if((fsrc)== -1){
		printf("[!] File doesn't exist or invalid \n"); // alert for invalid
	}else{
		close(fsrc);// experiment for algorithm IOs
		fsrc = open(pathsrc,O_WRONLY|O_TRUNC|,S_IWUSR|S_IRUSR); // experiment for algorithm IOs
		sizebuff = sizeof(fsrc);// regen the empty
		void *nanite = malloc(sizebuff);
		memset(nanite,0,sizebuff);
		// read pointer size the write much as size file
		write(nanite,fsrc); // write zero as much like past sizebuff
		while((fsrc)!=EOF){
			write(nanite,fsrc); // write zero as much like past sizebuff
			// mem function ,contradicted with the fputs function
		}
		close(fsrc); // close fsrc after read
		free(nanite);
		for(int i=0;i = strlen(pathsrc);i++){
				int namo = strlen(pathsrc);
				a = rename(pathsrc,"0"*namo);
				namo--
		} // obfuse name regen fake name
		remove(a);
	}
	if(verb != NULL){
		printf ("[!] shred finish [%s]",pathsrc)
	}
	return 0;	
	}

int scr_mv(string psr, string pds){
	FILE *src , *dst;

	src = open(psr,O_WRONLY|O_TRUNC|,S_IWUSR|S_IRUSR);
	if((src)== -1){// be indicator for file which exist or denied permission
		printf("[*] File doesn't exist or invalid !\n");
	}else{
		dst = open(pds,O_WRONLY|O_TRUNC|,S_IWUSR|S_IRUSR);
		if((dst)==-1){
			printf("[*] Path not exist \n");
		}
		write(src,dst);// read the size , and make use off
		while((src)!= EOF){
			write(src,dst);
		}
		close(dst);
		close(src);
		ovwrt_buf(psr);
	}
	return 0;
}

int clone_f(char path1,char argv[2]){
	FILE *src , *dst;

	src = open(psrc,O_RDONLY|O_TRUNC|,S_IWUSR|S_IRUSR);
	if((src ==-1){// be indicator for file which exist or denied permission
		printf("[*] File doesn't exist or invalid !\n");
	}else{
		dst = open(psrc,O_WRONLY|O_TRUNC|,S_IWUSR|S_IRUSR);
		write(src,dst);// read the size , and make use off
		while((src)!= EOF){
			write(src,dst);
		}
		close(dst);
		close(src);
		return 0;}

void unlock(char path,char r){
	FILE *file;  // pointer for file
	DIR *dfile;  // directory which contains file
	struct dirent *enmfile; // pointer for enumed file list to an array
	// create array and looping

	if((file = fopen(path))==NULL){
		dfile = opendir(path);
		enmfile = readdir(dfile);
		switch(r){ // file isn't
			case'1':
			while(enmfile){// shred entire memory
				ovwrt_buf(enmfile->d_name)
			}
			break;
			case'2':
			while(enmfile){ // secure move function
				scr_mv(enmfile->d_name, argv[2])
			}
			break;
			case'3':
			while(enmfile){ // clone entire memory
				clone_f(enmfile->d_name, argv[2])
			}
			break;
			case'4':
			while(enmfile){// shred entire memory
				ovwrt_buf(enmfile->d_name,1)
			}
			break;
		}
		}
	if((dfile = opendir(path))==NULL){
		switch(r){ // if directory are not
			case'1'://for shred
			ovwrt_buf(file);
			return 0;
			break;
			case'2'://for migrae
			scr_mv(file,argv[2]);
			return 0;
			break;
			case'3':// for clone
			clone_f(file,argv[2]);
			return 0;
			break;
			case'4'://for shred with verbose
			ovwrt_buf(file,1);
			return 0;
		}
		// list the file on directory
		// make it to array
	}
	return 0;
	}

int essential_f(char w){
	switch(w){
		case 'shred':
		unlock(argv[2],1);
		break;
		case 'shredv':
		unlock(argv[2],4);
		break;
		case 'migrate':
		unlock(argv[2],2);
		break;
		case 'clone':
		unlock(argv[2],3);
		break;
	}
	return 0;
}

void helpme(){
	prntf("lsmmr \n ver 1.0 \n wrotte : Yoghaswara Hadi Nugroho (lapua92) \n help ; \n usage : lsmmr [OPTION] [ARG1] [ARG2] \n OPTIONS : \n shred , for wipe files \n migrate , copy data from ARG1 to ARG2 \n clone , duplicate entire data to ARG2")
}

int main(char argc, char argv[]){
	// initiator for checking argument existence
	initgraph();
	if( argc == NULL ){
		printf(" -h for help", );
		return 0;
	}
	if(argv[1] == NULL){
		printf("-h for help\n");
	}
	if(argv[2] == NULL){
		printf("-h for help\n");
	}

	if(argv[1] == "shred"){
		essential_f(shred)
	}else if(argv[1] == "migrate"){
		essential_f(migrate)
	}else if(argv[1] == "clone"){
		essential_f(clone)
	}else if(argv[1] == "shredv"){ // using verbose
		essential_f(shred)
	}/*else if(argv[1] == "migratev"){ // usingerbose
		essential_f(migrate)
	}else if(argv[1] == "clonev"){
		essential_f(clone)

	}*/else{
		printf(" -h for help", );
		return 0;
	}
	return 0;
}

/*
 footnote

 - fix verbose add into primary function
 - use linux file control function for effective decreased delay times
 - 
