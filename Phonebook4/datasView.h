#pragma once
#include <Query.h>
#include <string>
#include <xstring>
#include <string>
#include <WinUser.h>
#include <winspool.h>
#include <ObjIdl.h>
#include <list>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;
ref class dataGridView {

public:
	dataGridView();
	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStrifBuilder;

	void ConnectToDB() {
		
		connStrifBuilder = gcnew SqlConnectionStringBuilder();
		connStrifBuilder->DataSource = "LAPTOP-8IOTANJP\\SQLEXPRESS";
		connStrifBuilder->InitialCatalog = "FriendsPhones";
		connStrifBuilder->IntegratedSecurity = true;

		conn = gcnew SqlConnection(Convert::ToString(connStrifBuilder));


	}
public:
	void Select(String^ nameFriend) {
		try {
			ConnectToDB();
			String^ cmdText = "SELECT nameFriend FROM dbo.FriendsPhones";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
			
			//cmd->Parameters->Equals("@nameFriendVstavka", nameFriend);
			conn->Open();
			cmd->ExecuteNonQuery();
			SqlDataReader^ reader = cmd->ExecuteReader();
			List <std::string> data = gcnew List <std::string>();
			while (reader.Read()) {
				data-> Add(new -> string[0]);
				data[data.Count - 1][0];
				reader[0] to String;
			}
			reader.Close();
			conn->Close();
			foreach((string[]) = std::ranges::in_out_result::in data);
				dataGridView1 -> Rows-> Add(string);

		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}
};
