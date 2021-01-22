<?php
namespace octetos
{

		class Datconnect
		{
			private $host;
			private $user;
			private $password;
			private $database;
			private $port;
			
			public function create($h,$u,$pass,$d,$po)
			{
				$this->host = $h;
				$this->user = $u;
				$this->password = $pass;
				$this->database = $d;
				$this->port = $po;
			}
			public function getHost()
			{
				return $this->host;
			}
			public function getUser()
			{
				return $this->user;
			}
			public function getPassword()
			{
				return $this->password;
			}
			public function getDatabase()
			{
				return $this->database;
			}
			public function getPort()
			{
				return $this->port;
			}
		}
		
		
		class Datresult
		{
			private $result;
			private $actualRow;
			
			public function setResult($rs)
			{
				$this->result = $rs;
			}
			
			public function nextRow()
			{
				$this->actualRow = mysqli_fetch_assoc($this->result);
				if($this->actualRow) return true;
				return false;
			}
			public function getString($field)
			{
				return $this->actualRow[$field];
			}
			public function getFloat($field)
			{
				return $this->actualRow[$field];
			}
			
			public function getNumRow()
			{
				return mysqli_num_rows($this->result);
			}
		}
		
		
		class Connector 
		{
			private $connection;
			
			public function connect($datconn)
			{
				$this->connection = mysqli_connect($datconn->getHost(),$datconn->getUser(), $datconn->getPassword(), $datconn->getDatabase());
				
				if (mysqli_connect_errno()) return false;
				return true;
			}
			public function close()
			{
			}
			public function execute($str)
			{
				$ret = mysqli_query($this->connection, $str);
				if(mysqli_connect_errno())
				{
					return null;
				}
				$dr = new Datresult();
				$dr->setResult($ret);
				return $dr;
			}
			public function update($str,$rs)
			{
				//echo "<br>str : " . $str;
				if(is_null($this->execute($str))) return false;
				return true;
			}
			public function select($str)
			{
				//echo "str : " . $str;
				return $this->execute($str);
			}
			public function insert($str,$rs)
			{
				//echo "<br>str : " . $str;
				if(is_null($this->execute($str))) return false;
				return true;
			}
			public function delete($str,$rs)
			{
				if(is_null($this->execute($str))) return false;
				return true;
			}
			
			//mariadb especialist
			public function last_inserted_id()
			{
				return mysqli_insert_id($this->connection);
			}
		}
	
}
?>
