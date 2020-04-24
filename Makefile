all: naivedb create fileconverter indexer srchindx

naivedb: naivedb.o interfaceFunctions.o 
	gcc naivedb.o interfaceFunctions.o -o naivedb
naivedb.o: naivedb.c
	gcc naivedb.c -c
interfaceFunctions.o: interfaceFunctions.c
	gcc interfaceFunctions.c -c

fileconverter: fileconverter.o filect.o
	gcc fileconverter.o filect.o -o fileconverter
fileconverter.o: fileconverter.c
	gcc fileconverter.c -c
filect.o: filect.c
	gcc filect.c -c

create: create.o filedirectory.o
	gcc create.o filedirectory.o -o create
filedirectory.o: filedirectory.c
	gcc filedirectory.c -c
create.o : create.c
	gcc create.c -c

indexer: indexer.o index.o
	gcc indexer.o index.o -o indexer
index.o: index.c
	gcc index.c -c
indexer.o: indexer.c
	gcc indexer.c -c

srchindx: srchindx.o srx.o
	gcc srchindx.o srx.o -o srchindx
srchindx.o: srchindx.c 
	gcc srchindx.c -c
srx.o:	srx.c
	gcc srx.c -c

clean:
	rm -f *.o 
	rm -f fileconverter naivedb create indexer srchindx