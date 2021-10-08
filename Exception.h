#pragma once

class Exception
{

public:

	Exception(char error[]) : m_error(error) {}

	char* what() {
		return m_error;
	}


private:

	char* m_error;

};

