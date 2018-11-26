#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "step.h"

int isDirExist(const char * DirectoryPath);

int main(const int argc, const char ** argv)
{

    strncpy(install_path, argv[1], 1000);
    if (isDirExist(install_path) == 0)
    {
        printf("ERROR - Tool path is invalid: %s\n", install_path);
        exit(0);
    }

    if(strcmp(argv[2], "--mapping") == 0)
    {
        printf("step 1 (Gene mapping and pairing) is processing.\n");
        step1(argc, &argv[3]);
    }
    else if(strcmp(argv[2], "--expressionmatrix") == 0)
    {
        printf("step 2 (merge catalog to the matrix) is processing.\n");
        step2(argc, &argv[3]);
    }
    else if(strcmp(argv[2], "--filtering") == 0)
    {
        printf("step 3 (TPM normalizationa dn filtering) is processing.\n");
        step3(argc, &argv[3]);
    }
    else if(strcmp(argv[2], "--biclustering") == 0)
    {
        printf("step 4 (biclustering) is processing.\n");
        step4(argc, &argv[3]);
    }
    else if(strcmp(argv[2], "--sample_enrichment") == 0)
    {
        printf("step 5 (sample enrichment) is processing.\n");
        step5_sample(argc, &argv[3]);
    }
    else if(strcmp(argv[2], "--gene_enrichment") == 0)
    {
        printf("step 5 (gene enrichment) is processing.\n");
        step5_gene(argc, &argv[3]);
    }
    else
    {
        printf("wrong arguments\n");
    }
}



int isDirExist(const char * DirectoryPath)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (DirectoryPath)) != NULL) 
    {
        /* print all the files and directories within directory */
        closedir (dir);
        return 1;
    } 
    else 
    {
        /* could not open directory */
        return 0;
    }
}