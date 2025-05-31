#include "AdminManager.h"
#include "BookManager.h"

AdminManager::AdminManager(){
    last_id = 0;
}
void AdminManager::AccessSystem(){
   int choice = showReadMenuAdmin({"Login","Sign up"});
   if(choice == 1)
      DoLogin();
    else 
      DoSignUp();
}

void AdminManager::LoadDatabase(){
   BookManager bookManagerSystem;
   last_id = 0;
   adminId_bookObject_map.clear();

   vector<string> lines = ReadFileLines("AdminList.txt");
   for(auto &line: lines){
    Admin admin(line);
    adminId_booksObject_map[admin.GetAdminId()] = bookManagerSystem.GetlistofBooks(admin.GetBooksIdsFromAdmin()) ;
   }

}
void AdminManager::DoLogin(){
   
}
void AdminMangaer::DoSignUp(){

}