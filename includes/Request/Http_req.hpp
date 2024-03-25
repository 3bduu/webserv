#ifndef HTTP_REQ
#define HTTP_REQ
#include <iostream>
#include "../Server.hpp"
#include <cerrno>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include "../../includes/Multiplex.hpp"
#include "dirent.h"
#define IS_DIR   0
#define IS_FILE 1
#define IS_RED 2
class Http_req
{
public:
    struct golbal_info
    {
        
    };
    

public:
   /// this the start line 
    std::string req;
    std::string _target;
    
    std ::string method;
    std::string path;
    std ::string http_ver;
    std ::string body;

   std::map<std::string, std::string> header; 
    Server server;
    Location _loca;
    int byterec;


public:
    Http_req();
    Http_req& operator=(const Http_req &obj);
    void debugFunction();
    Http_req(std::string req,int byterec, Multiplex::listeners_t listenrs);
   void parse_re(std ::string bufer,int bytee);
   int StautRe(std ::string request);
    int MoreValidation();
    void LetGet();
    void CheckLoc();
    ~Http_req();


    /*  Getter*/
  const std::string& getTarget() const;
  const std::string& getBody() const;
    const std::string& getMethod() const;
    const std::string& getPath() const;
    const std::string& getHttpVersion() const;
    const std::map<std::string, std::string>& getHeader() const;
    const Server& getServer() const;
    const Location& getLocation() const;
};

#endif