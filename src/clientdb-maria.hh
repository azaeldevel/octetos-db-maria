#ifndef OCTETOS_MARIADB_HH
#define OCTETOS_MARIADB_HH

#include <vector>
#include <string>


#if defined WINDOWS_MINGW && defined CODEBLOCKS
    #include <clientdb.hh>
#elif defined LINUX && defined CODEBLOCKS
    #include <clientdb.hh>
#else
    #include <octetos/db/clientdb.hh>
#endif

namespace octetos
{
namespace db
{
namespace maria
{

        class DECLSPCE_DLL Datconnect : public db::Datconnect
        {
        public:
            Datconnect(const std::string& host, unsigned int port,const std::string& database,const std::string& usuario,const std::string& password);
            Datconnect(const Datconnect& obj);
            const Datconnect& operator=(const Datconnect&);
            ~Datconnect();
            Datconnect();
        };

	class DECLSPCE_DLL Row
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


	class DECLSPCE_DLL Datresult : public db::Datresult
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


	class DECLSPCE_DLL Connector : public db::Connector
	{
	public:
		virtual ~Connector();
		Connector();
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
    typedef maria::Datconnect DECLSPCE_DLL Datconnect __attribute__ ((deprecated));
    typedef maria::Row DECLSPCE_DLL Row __attribute__ ((deprecated));
    typedef maria::Datresult DECLSPCE_DLL Datresult __attribute__ ((deprecated));
    typedef maria::Connector DECLSPCE_DLL Connector __attribute__ ((deprecated));
}
}
}


#endif
