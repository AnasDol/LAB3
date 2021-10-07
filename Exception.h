#pragma once
class Exception
{

public:

	Exception(char error[]) : m_error(error) {}

	char* GetError() {
		return m_error;
	}


private:

	char* m_error;

};

