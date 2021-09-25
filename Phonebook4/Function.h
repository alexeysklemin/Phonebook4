#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;
ref class Function {

public:
	Function();
	SqlConnection^ conn;
	SqlConnectionStringBuilder^ connStrifBuilder;

	void ConnectToDB() {
		//Data Source=LAPTOP-8IOTANJP\SQLEXPRESS;Initial Catalog=FriendsPhones;Integrated Security=True

		connStrifBuilder = gcnew SqlConnectionStringBuilder();
		connStrifBuilder->DataSource = "LAPTOP-8IOTANJP\SQLEXPRESS";
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
			conn->Open();
		}
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}
};