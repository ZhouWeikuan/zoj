#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 100,
};

char buffer[Size];

void parse(){
	int i;
	static int tstnum = 1;
	int host;
	int port = -1;
	int path = -1;
	/* find the protocol */
	for(i=0;buffer[i] && buffer[i] !=':'; i++){
		;
	}
	printf("URL #%d\n", tstnum++);
	buffer[i] = 0;
	host = i + 3;
	for(i = host; buffer[i] && buffer[i] !=':' && buffer[i] !='/';i++){
		;
	}
	if(buffer[i] ==0){
		;
	}else if(buffer[i] =='/'){
		path = i + 1;
		buffer[i] = 0;
	} else {
		port = i+1;
		buffer[i] = 0;
		for(i=port; buffer[i] && buffer[i] !='/'; i++)
			;
		if(buffer[i] =='/'){
			path = i+1;
			if(buffer[path]==0)
				path =-1;
			buffer[i] = 0;
		} 
	}

	printf("Protocol = %s\n", buffer);
    printf("Host     = %s\n", &buffer[host]);
	printf("Port     = %s\n", port!=-1? &buffer[port]:"<default>");
	printf("Path     = %s\n", path!=-1? &buffer[path]:"<default>");
}

int main(){
	int tstcase;
	
	scanf("%d", &tstcase);
	while(tstcase --){
		scanf("%s", buffer);
		parse();
		printf("\n");
	}

	return 0;
}
