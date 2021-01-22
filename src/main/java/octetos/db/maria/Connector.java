
package octetos.db.maria;


import java.sql.Connection;
import java.sql.SQLException;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;

/**
 *
 * @author azael
 */
public class Connector implements octetos.db.Connector
{    
    private Connection connection;
    private int liID;
    
    public int last_inserted_id()
    {
        return liID;
    }
    @Override
    public boolean delete(String str,ResultSet rs) throws SQLException
    {
        Statement stmt = null;

        stmt = connection.createStatement();
        rs = stmt.executeQuery(str);
        if(rs != null) return true;
        return false;        
    }
    @Override
    public ResultSet select(String str) throws SQLException
    {
        Statement stmt = null;

        stmt = connection.createStatement();
        return stmt.executeQuery(str);   
    }
    @Override
    public boolean update(String str,ResultSet rs) throws SQLException
    {
        Statement stmt = null;

        stmt = connection.createStatement();
        stmt.executeUpdate(str);
        return true;       
    }
    @Override
    public boolean insert(String str,ResultSet rs) throws SQLException
    {
        //System.out.println("str : " + str);
        //System.out.println("Conector::insert Step 1");
        PreparedStatement pstmt = connection.prepareStatement(str, Statement.RETURN_GENERATED_KEYS);
        //System.out.println("Conector::insert Step 2");
        pstmt.executeUpdate();
        //System.out.println("Conector::insert Step 3");
        ResultSet keys = pstmt.getGeneratedKeys();
        //System.out.println("Conector::insert Step 4");
        if(keys != null)
        {
            //System.out.println("Conector::insert Step 4");
            if(keys.next())
            {
                liID = keys.getInt(1);
            }
            else
            {
                liID = 0;
            }
            keys.close();
        }
        pstmt.close();
        //System.out.println("Conector::insert Step 5");
        return true;       
    }
    @Override
    public ResultSet execute(String str,ResultSet rs) throws SQLException
    {
        Statement stmt = null;

        stmt = connection.createStatement();
        return stmt.executeQuery(str);
        
    }
    @Override
    public void close() throws SQLException
    {
        connection.close();
    }
    @Override
    public boolean connect(octetos.db.Datconnect dat) throws SQLException
    {
        connection = DriverManager.getConnection("jdbc:mysql://" + dat.getHost()  + ":" + dat.getPort() + "/" + dat.getDatabase(),dat.getUser(),dat.getPassword());
        
        return connection.isValid(50000);
    }
}
