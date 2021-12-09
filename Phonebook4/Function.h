#pragma once
#include "MyForm.h"

//using namespace Phonebook4::MyForm;
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
		/*Server = localhost;
		Database = FriedsPhones;
		Trusted_Connection = true;*/
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
			String^ cmdText = "SELECT nameFriend FROM friends";
			SqlCommand^ cmd = gcnew SqlCommand(cmdText, conn);
			cmd->Parameters->Equals("@nameFriendVstavka", nameFriend);
			conn->Open();
			SqlDataReader^ myReader;
			cmd->ExecuteNonQuery();
			//SqlCommand^ SelectCommand();
			//System::Data::SqlClient::SqlDataAdapter::SelectCommand::set
			//SqlCommand^ MySqlAdapter = gcnew SqlDataAdapter;
		
			SqlDataAdapter^ sda = gcnew SqlDataAdapter();
			sda->SelectCommand = cmd;
			DataTable^ dbdataset = gcnew DataTable();
			sda->Fill(dbdataset);
			BindingSource^ bSource = gcnew BindingSource();
			bSource->DataSource = dbdataset;
			Phonebook4::MyForm::dataGridView1 ->DataSource = bSource;
			sda->Update(dbdataset);
			
			cmdText = "SELECT phone FROM phone INNER JOIN friends ON friends.ID_driend = phone.ID_friend";
			cmd = gcnew SqlCommand(cmdText, conn);
			cmd->Parameters->Equals("@nameFriendVstavka", nameFriend);
			conn->Open();
			//SqlDataReader^ myReader;
			cmd->ExecuteNonQuery();
			//SqlCommand^ SelectCommand();
			//System::Data::SqlClient::SqlDataAdapter::SelectCommand::set
			//SqlCommand^ MySqlAdapter = gcnew SqlDataAdapter;

			//SqlDataAdapter^ sda = gcnew SqlDataAdapter();
			sda->SelectCommand = cmd;
			DataTable^ dbdataset2 = gcnew DataTable();
			sda->Fill(dbdataset2);
			BindingSource^ bSource1 = gcnew BindingSource();
			bSource1->DataSource = dbdataset2;
			Phonebook4::MyForm::dataGridView2->DataSource = bSource1;
			sda->Update(dbdataset2);
		}
		

		
		finally {
			if (conn != nullptr) {
				conn->Close();
			}
		}
	}
};