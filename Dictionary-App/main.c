#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
	{                                   //S�zl�k Uygulamas�             
		    //---------------------------------------------------------------------------------  
	  int secenek,k=0,i=0;
	  
	  char aranan[20],silinecek[15],guncelle[15];
	  
	  while(1)
	    {	
	    printf("  :::Secenekler:::\n\n");
	    
	  	printf("1-Tum kelimeleri Goster\n\n2-Ara\n\n3-Ekle\n\n4-Sil\n\n5-Duzenle\n\n-----------------------\n");
	    
	  	scanf("%d",&secenek);
	    
		FILE *dosya,*yeni;
	    
		char trKelime[200][15],ingKelime[200][15];
		
	  	switch(secenek)
		  {
		  	case 1:                                     //Listele      
		  	//---------------------------------------------------------------------------------  
				dosya=fopen("kelimeler.txt","r");//dosya a�ma i�lemi
			
				if(dosya!=NULL)
				{
					while(!feof(dosya))//dizinin sonuna kadar git. 
					{
						fscanf(dosya,"%s %s",&trKelime[i],&ingKelime[i]);
						printf("%s ........ :%s\n",trKelime[i],ingKelime[i]);
					 	//i++; 
					}            
				}
				else
				{
					printf("kelimeler.txt Dosyas� Bulunamadi.");
				}	
				fclose(dosya);
			break;
			
			case 2:                                     //Arama i�lemleri
			    //---------------------------------------------------------------------------------  
			   printf("\nAramak istediginiz kelimenin turkcesini giriniz : ");
			    
			   scanf("%s",&aranan);
			   
			   dosya=fopen("kelimeler.txt","r");
			   
				   while(dosya!=NULL)//strcmp(trKelime[k],aranan)!=0
			   	   {
				     fscanf(dosya,"%s %s",&trKelime[k],&ingKelime[k]);
					 
					 if(strcmp(trKelime[k],aranan)==0)
			   	      {
			   	        printf("\nAradiginiz kelime ve karsiligi : %s %s",trKelime[k],ingKelime[k]);
			   	        break;
					  }
				   }
				     
				   if(strcmp(trKelime[k],aranan)!=0)
			   	      {
					 	printf("Aradiginiz kelime bulunamadi...");
					  }
			     fclose(dosya);
			break;
			
			case 3:                                        //Sona Ekleme
			//---------------------------------------------------------------------------------  
			    dosya=fopen("kelimeler.txt","a");
			    char TR[15],ING[15];
			    printf("Turkce Kelimeyi Giriniz:  ");
				scanf("%s",TR);
			    printf("Ingilizce Karsiligini Giriniz:  ");
				scanf("%s",ING);
			    fprintf(dosya," %s %s",TR,ING);
			    printf("\n\nKelime sozluge Eklendi.");
			    fclose(dosya);
			    break;                                      //Silme i�lemleri
		  	 //---------------------------------------------------------------------------------  
		    case 4:
		    	dosya=fopen("kelimeler.txt","r");
		    
				yeni=fopen("kelimelerGecici.txt","w");
		    
				printf("\nSilinecek kelimenin turkcesini giriniz: ");
		    
				scanf("%s",&silinecek);
		    	 
		    	
		    	 while(!feof(dosya))//strcmp(trKelime[k],aranan)!=0
			   	   {
				    fscanf(dosya,"%s %s",&trKelime[k],&ingKelime[k]);
					 
					 if(strcmp(trKelime[k],silinecek)==0)
			   	      {
			   	        fscanf(dosya,"%s %s",trKelime[k],ingKelime[k]);
			   	        break;
					  }
					  
					fprintf(yeni," %s %s",&trKelime[k],&ingKelime[k]);//yeni olu�turulan .txt nin i�ine aktar�yoruz.Silinen Hari�
					
				   }
				    printf("Kelime silindi.");
				  
		    	fclose(dosya);
		    	fclose(yeni);
		    	
		    	remove("kelimeler.txt");
                rename("kelimelerGecici.txt","kelimeler.txt");//temp dosyas� ile ana dosyay� de�i�tirdik. :)
		    	
				break;                                     //D�zenle
				//-------------------------------------------------------------------------------------  
				case 5:
				
				dosya=fopen("kelimeler.txt","r");
		    
				yeni=fopen("kelimelerGecici.txt","w");
		    
				printf("\nGuncellenecek kelimenin turkcesini giriniz: ");
		    
				scanf("%s",&guncelle);
		    	
		    	 while(!feof(dosya))//strcmp(trKelime[k],aranan)!=0 da kullan�labilir.
			   	   {
				    fscanf(dosya,"%s %s",trKelime[k],ingKelime[k]);
					 
					 if(strcmp(trKelime[k],guncelle)==0)//strstr de kullanabilirdik.
			   	      {
			   	        printf("Yeni Bilgiler\n\n");
			   	        printf("Turkce kelime :");scanf("%s",&trKelime[k]);
			   	        printf("�ngilizce kelime :");scanf("%s",&ingKelime[k]);
					  }
					  
					fprintf(yeni," %s %s",trKelime[k],ingKelime[k]);//yeni olu�turulan .txt nin i�ine aktar�yoruz.Silinen Hari�
					
				   }
				 
		    	fclose(dosya);
		    	fclose(yeni);
		    	
		    	remove("kelimeler.txt");
                rename("kelimelerGecici.txt","kelimeler.txt");
					
					break;
		  } 
		  printf("\n\n");
	}
		return 0;
	}
