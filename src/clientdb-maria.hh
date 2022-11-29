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

#ifndef OCTETOS_DB_MARIADB_HH
#define OCTETOS_DB_MARIADB_HH

#include <vector>
#include <string>


#if EXPORTING_OCTETOS_DB_MARIA_DLL
	#if _MSC_VER
		#define OCTETOS_DB_MARIA_DECLSPCE_DLL __declspec(dllexport)
	#elif __GNUG__

	#endif
#elif IMPORTING_OCTETOS_DB_MARIA_DLL
	#if _MSC_VER
		#define OCTETOS_DB_MARIA_DECLSPCE_DLL __declspec(dllimport)
	#elif __GNUG__

	#endif
#else
	#define OCTETOS_DB_MARIA_DECLSPCE_DLL
#endif


#if defined WINDOWS_MINGW && defined CODEBLOCKS
    #include <clientdb.hh>
#elif defined LINUX && defined CODEBLOCKS
    #include <clientdb.hh>
#else
    #error "Plataforma desconocida"
#endif

namespace octetos
{
namespace db
{
namespace maria
{

        class Datconnect : public db::Datconnect
        {
        public:
            Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datconnect(const Datconnect& obj);
            const Datconnect& operator=(const Datconnect&);
            ~Datconnect();
            Datconnect();
        };

	class  Row
	{
	private:
		void* row;
	public:
#ifdef COLLETION_ASSISTANT
		Row(Datresult* rs,void* row);
#endif
		//virtual const char* operator[](unsigned long long index);
		virtual ~Row();
		Row();
		Row(void* row);
		Row(const Row& row);
		//retrive data field by index
		virtual char getchar(FieldNumber field)const;
		virtual unsigned char getuchar(FieldNumber field)const;
		virtual signed char getschar(FieldNumber field)const;
		virtual short getshort(FieldNumber field)const;
		virtual unsigned short getushort(FieldNumber field)const;
		virtual int getint(FieldNumber field)const;
		virtual unsigned int getuint(FieldNumber field)const;
		virtual long getl(FieldNumber field)const;
		virtual unsigned long getul(FieldNumber field)const;
		virtual long long getll(FieldNumber field)const;
		virtual unsigned long long getull(FieldNumber field)const;
		virtual float getfloat(FieldNumber field)const;
		virtual double getdouble(FieldNumber field)const;
		virtual std::string getString(FieldNumber field)const;
		//retrive data field by name
		virtual char getchar(const std::string&)const;
		virtual unsigned char getuchar(const std::string&)const;
		virtual short getshort(const std::string&)const;
		virtual unsigned short getushort(const std::string&)const;
		virtual int getint(const std::string&)const;
		virtual unsigned int getuint(const std::string&)const;
		virtual long getl(const std::string&)const;
		virtual unsigned long getul(const std::string&)const;
		virtual long long getll(const std::string&)const;
		virtual unsigned long long getull(const std::string&)const;
		virtual float getfloat(const std::string&)const;
		virtual double getdouble(const std::string&)const;
		virtual std::string getString(const std::string&)const;
	};


	class Datresult : public db::Datresult
	{
	private:
		Row* actualRow;

	public:
		virtual ~Datresult();
		Datresult(void* result);
		Datresult();
		//virtual db::Row* operator[](unsigned long long index);
		//virtual db::Row* next() __attribute__ ((deprecated));
		virtual bool nextRow();
		//virtual db::Row* getRow();
		//retrive data field by index
		virtual char getchar(FieldNumber field)const;
		virtual unsigned char getuchar(FieldNumber field)const;
		virtual signed char getschar(FieldNumber field)const;
		virtual short getshort(FieldNumber field)const;
		virtual unsigned short getushort(FieldNumber field)const;
		virtual int getint(FieldNumber field)const;
		virtual unsigned int getuint(FieldNumber field)const;
		virtual long getl(FieldNumber field)const;
		virtual unsigned long getul(FieldNumber field)const;
		virtual long long getll(FieldNumber field)const;
		virtual unsigned long long getull(FieldNumber field)const;
		virtual float getfloat(FieldNumber field)const;
		virtual double getdouble(FieldNumber field)const;
		virtual std::string getString(FieldNumber field)const;
		//retrive data field by name
		virtual char getchar(const std::string&)const;
		virtual unsigned char getuchar(const std::string&)const;
		virtual short getshort(const std::string&)const;
		virtual unsigned short getushort(const std::string&)const;
		virtual int getint(const std::string&)const;
		virtual unsigned int getuint(const std::string&)const;
		virtual long getl(const std::string&)const;
		virtual unsigned long getul(const std::string&)const;
		virtual long long getll(const std::string&)const;
		virtual unsigned long long getull(const std::string&)const;
		virtual float getfloat(const std::string&)const;
		virtual double getdouble(const std::string&)const;
		virtual std::string getString(const std::string&)const;
		//retrive field meta-data
	};


	class Connector : public db::Connector
	{
	public:
		Connector();
		virtual ~Connector();
		const char* serverDescription();
		virtual core::Semver getVerionServer() const;
		//
		virtual bool connect(const db::Datconnect& connector);
		virtual bool execute(const std::string& str,db::Datresult&);
		virtual bool insert(const std::string&,db::Datresult&);
		virtual bool select(const std::string& str,db::Datresult&);
		virtual bool update(const std::string&,db::Datresult&);
		virtual bool remove(const std::string&,db::Datresult&);
		virtual bool commit();
		virtual bool begin();
		virtual bool rollback();
		virtual void close();
		virtual RowNumber last_inserted_id();
		//virtual bool insert2(const std::string&,db::Datresult&);
		virtual int affected();
	};
}

namespace mariadb
{
    typedef maria::Datconnect Datconnect __attribute__ ((deprecated));
    typedef maria::Row Row __attribute__ ((deprecated));
    typedef maria::Datresult Datresult __attribute__ ((deprecated));
    typedef maria::Connector Connector __attribute__ ((deprecated));
}

}
}


#endif
