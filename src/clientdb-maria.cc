
/**
 *
 *  This file is part of octetos-db-maria.
 *  octetos-db-maria is an API to access database, MariaDB component.
 *  Copyright (C) 2018  Azael Reyes
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * */

#if defined LINUX_ARCH
	#include <mysql/mysql.h>
#elif defined LINUX_GENTOO
	#include <mariadb/mysql.h>
#elif defined LINUX_DEBIAN
	#include <mariadb/mysql.h>
#elif defined WINDOWS_MINGW && defined BUILDING_DLL
    #include <mariadb/mysql.h>
#else
	#error "Plataforma desconocida."
#endif


#include <iostream>
#if defined WINDOWS_MINGW
    #include <Artifact.hh>
#else
    #include <octetos/core/Artifact.hh>
#endif
#include <string.h>


#include "clientdb-maria.hh"
#ifdef HAVE_CONFIG_H
    #include "config.h"
#elif defined WINDOWS_MINGW && defined CODEBLOCKS
    #include "config-cb.h"
#elif defined LINUX && defined CODEBLOCKS
    #include "config-cb.h"
#endif



namespace octetos
{
namespace db
{
namespace maria
{
	
	char Row::getchar(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned char Row::getuchar(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	short Row::getshort(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned short Row::getushort(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned int Row::getuint(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned long Row::getul(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned long long Row::getull(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	float Row::getfloat(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	double Row::getdouble(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	int Row::getint(const std::string&) const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	long Row::getl(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	long long Row::getll(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	std::string Row::getString(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}

	char Row::getchar(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? r[field][0] : 0;
	}
	unsigned char Row::getuchar(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? (unsigned char)r[field][0] : '\0';
	}
	short Row::getshort(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? (short)std::stoi(r[field]) : '\0';
	}
	unsigned short Row::getushort(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? (unsigned short)std::stoul(r[field]) : 0;
	}
	unsigned int Row::getuint(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? (unsigned int)std::stoul(r[field]) : 0;
	}
	unsigned long Row::getul(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::stoul(r[field]) : 0;
	}
	unsigned long long Row::getull(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::stoull(r[field]) : 0;
	}
	float Row::getfloat(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::stof(r[field]) : 0;
	}
	double Row::getdouble(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::stod(r[field]) : 0;
	}
	int Row::getint(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atol(r[field]) : 0;
	}
	long Row::getl(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atol(r[field]) : 0;
	}
	long long Row::getll(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? std::atoll(r[field]) : 0;
	}
	std::string Row::getString(FieldNumber field)const
	{
		MYSQL_ROW r = (MYSQL_ROW)row;
		return r[field] ? r[field] : "";
	}
	Row::~Row()
	{
#ifdef COLLETION_ASSISTANT
		if(getCountChilds() > 0)
		{
			std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
		}
#endif
	}
	Row::Row(const Row& r)
	{
		this->row = r.row;
	}
	Row::Row()
	{

	}
	Row::Row(void* row)
	{
		this->row = row;
	}



  	char Datresult::getchar(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned char Datresult::getuchar(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	short Datresult::getshort(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned short Datresult::getushort(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned int Datresult::getuint(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned long Datresult::getul(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	unsigned long long Datresult::getull(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	float Datresult::getfloat(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	double Datresult::getdouble(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	int Datresult::getint(const std::string&) const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	long Datresult::getl(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	long long Datresult::getll(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}
	std::string Datresult::getString(const std::string&)const
	{
		throw NotSupportedExcetion("Aun se trabaja en esta cracteristica(mariadb).");
	}

	char Datresult::getchar(FieldNumber field)const
	{
		return actualRow ? actualRow->getchar(field) : 0;
	}
	unsigned char Datresult::getuchar(FieldNumber field)const
	{
		return actualRow ? actualRow->getuchar(field) : 0;
	}
	short Datresult::getshort(FieldNumber field)const
	{
		return actualRow ? actualRow->getshort(field) : 0;
	}
	unsigned short Datresult::getushort(FieldNumber field)const
	{
		return actualRow ? actualRow->getushort(field) : 0;
	}
	unsigned int Datresult::getuint(FieldNumber field)const
	{
		return actualRow ? actualRow->getuint(field) : 0;
	}
	unsigned long Datresult::getul(FieldNumber field)const
	{
		return actualRow ? actualRow->getul(field) : 0;
	}
	unsigned long long Datresult::getull(FieldNumber field)const
	{
		return actualRow ? actualRow->getull(field) : 0;
	}
	float Datresult::getfloat(FieldNumber field)const
	{
		return actualRow ? actualRow->getfloat(field) : 0;
	}
	double Datresult::getdouble(FieldNumber field)const
	{
		return actualRow ? actualRow->getdouble(field) : 0;
	}
	int Datresult::getint(FieldNumber field) const
	{
		return actualRow ? actualRow->getint(field) : 0;
	}
	long Datresult::getl(FieldNumber field)const
	{
		return actualRow ? ((Row*)actualRow)->getl(field) : 0;
	}
	long long Datresult::getll(FieldNumber field)const
	{
		return actualRow ? ((Row*)actualRow)->getll(field) : 0;
	}
	std::string Datresult::getString(FieldNumber field)const
	{
		return actualRow ? ((Row*)actualRow)->getString(field) : "";
	}
	bool Datresult::nextRow()
	{
		MYSQL_ROW row  = mysql_fetch_row((MYSQL_RES*)result);
		if(actualRow)
		{
			delete actualRow;
		}
		actualRow = new Row(row);
#ifdef COLLETION_ASSISTANT
		addChild(actualRow);
#endif
		if(row) return true;
		return false;
	}

        Datresult::Datresult(void* result) : db::Datresult(result)
        {
			actualRow = NULL;
        }
	Datresult::Datresult()
	{
		actualRow = NULL;
	}
	Datresult::~Datresult()
	{
		if(actualRow)
		{
			delete actualRow;
		}
		if(getResult())
		{
			mysql_free_result((MYSQL_RES*)result);
		}
#ifdef COLLETION_ASSISTANT
		if(getCountChilds() > 0)
		{
			std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
		}
#endif
	}



        Datconnect::~Datconnect()
        {
#ifdef COLLETION_ASSISTANT
                if(getCountChilds() > 0)
                {
                        std::cerr << "Una instacia de '" << typeid(*this).name() << "' termino sin que todos sus hijos terminaran primero" << std::endl;
                }
#endif
        }
        Datconnect::Datconnect()
        {
			autocommit = true;
        }
        Datconnect::Datconnect(const Datconnect& obj) : db::Datconnect(obj)
        {
        }

        const Datconnect& Datconnect::operator=(const Datconnect& obj)
        {
             ((db::Datconnect&)*this)=obj;//llamar el construc de la clase base
             return *this;
        }

        Datconnect::Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& user,const std::string& password) : db::Datconnect(TypeServer::MariaDB,host,port,database,user,password)
        {
        }





    Connector::Connector()
   	{
		conn = NULL;
	}
	Connector::~Connector()
	{
		if(conn) 
		{
			mysql_close((MYSQL*)conn);
		}
	}
	bool Connector::select(const std::string& str,db::Datresult& rs)
	{
		return execute (str,rs);
	}
	bool Connector::update(const std::string& str,db::Datresult& rs)
	{
        return execute (str,rs);
	}
	bool Connector::remove(const std::string& str,db::Datresult& rs)
	{
		return execute (str,rs);
	}
	bool Connector::execute(const std::string& str,db::Datresult& rs)
	{
		if (mysql_query((MYSQL*)conn, str.c_str())  != 0)
		{
			std::string msg = "";
			msg = msg + "Server Error No. : '";
			msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
			msg = msg + "' ";
			msg = msg + mysql_error((MYSQL*)conn);
			msg = msg + " -> " + str;
			throw SQLException(msg);
		}
		MYSQL_RES *result = mysql_store_result((MYSQL*)conn);
		if (result == NULL && mysql_errno((MYSQL*)conn) != 0)
		{
			std::string msg = "";
			msg = msg + "Server Error No. : '";
			msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
			msg = msg + "' ";
			msg = msg + mysql_error((MYSQL*)conn);
			msg = msg + " -> " + str;
			throw SQLException(msg);
		}
		rs = (Result)result;
		return true;
	}
	core::Semver Connector::getVerionServer() const
	{
		core::Semver ver;
		ver.set(mysql_get_server_version((MYSQL*)conn),core::Semver::ImportCode::MySQL);

		return ver;
	}
        bool Connector::begin()
        {
            return false;
        }
	
	void Connector::close()
	{
		if(conn) 
		{
			mysql_close((MYSQL*)conn);
			conn = NULL;
		}
	}
        bool Connector::rollback()
        {
                if (conn != NULL)
                {
                        if(mysql_rollback((MYSQL*)conn) == 0)
                        {
                        return true;
                        }
                }

                return false;
        }
        bool Connector::commit()
        {
            if (conn != NULL)
            {
                if(mysql_commit((MYSQL*)conn) == 0)
                {
                    return true;
                }
            }

            return false;
        }
	int Connector::affected_rows()
	{
		return mysql_affected_rows((MYSQL*)conn);
	}
	bool Connector::insert(const std::string& str,db::Datresult&)
	{
		if (mysql_query((MYSQL*)conn, str.c_str()) == 0)
		{
			return true;
		}
		else
		{
			std::string msg = "";
			msg = msg + "Server Error No. : '";
			msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
			msg = msg + "' ";
			msg = msg + mysql_error((MYSQL*)conn);
			msg = msg + " -> " + str;
			throw SQLException(msg);
		}
	}
	/*
	bool Connector::insert2(const std::string& str,db::Datresult&)
	{
		if (mysql_query((MYSQL*)conn, str.c_str()) == 0)
		{
			return true;
		}
		else
		{
			std::string msg = "";
			msg = msg + "Server Error No. : '";
			msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
			msg = msg + "' ";
			msg = msg + mysql_error((MYSQL*)conn);
			msg = msg + " -> " + str;
			throw SQLException(msg);
		}
	}
	*/
	RowNumber Connector::last_inserted_id()
	{
		return mysql_insert_id((MYSQL*)conn);
	}
        /*const char* Connector::serverDescription()
        {
            return mysql_get_client_info();
        }*/
	bool Connector::connect(const db::Datconnect& dtcon)
	{
           	conn = mysql_init(NULL);
            if (conn == NULL)
            {
                std::string msg = "";
                msg = msg + "Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)conn);
				throw SQLException(msg);
            }
            if (mysql_real_connect((MYSQL*)conn, dtcon.getHost().c_str(), dtcon.getUser().c_str(), dtcon.getPassword().c_str(),dtcon.getDatabase().c_str(),dtcon.getPort(), NULL, 0) == NULL)
            {
                std::string msg = "";
                msg = msg + " Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)conn);
				throw SQLException(msg);
            }
            if(mysql_autocommit((MYSQL*)conn,dtcon.getAutocommit()) != 0)
            {
                std::string msg = "";
                msg = msg + "Server Error No. : '";
                msg = msg + std::to_string(mysql_errno((MYSQL*)conn));
                msg = msg + "' ";
                msg = msg + mysql_error((MYSQL*)conn);
				throw SQLException(msg);
            }
			datconn = &dtcon;
            return true;
	}
}
}
}
