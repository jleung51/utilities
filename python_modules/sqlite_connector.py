import sqlite3
import sys

from contextlib import closing

class SqliteConnector:
    '''Class to connect to and run queries on an SQLite3 Database.'''

    def __init__(self, db_path):
        self.__db_path = db_path

    def delete_all(self, table_name):
        '''Removes all rows from the table without deleting the table itself.'''
        print(
            'SqliteConnector: Preparing to delete all rows from table ' + \
            table_name + '.'
        )
        self.__query('DELETE FROM ' + table_name)

    def get(self, table_name: str, columns: list[str]):
        '''Returns all rows from the database with only the provided columns.'''
        if not table_name:
            print(
                'Error: Table name is required for SQLiteConnector::get()',
                file=sys.stderr
            )
            return
        if not columns:
            print(
                'Error: Non-empty list of columns is required for '+
                'SQLiteConnector::get()',
                file=sys.stderr
            )
            return

        # Example output: 'date, value'
        columns_string = ', '.join(columns)
        
        query_string = "SELECT " + columns_string + \
            " FROM " + table_name + ";"

        print('SqliteConnector: Preparing to retrieve columns ' + columns_string)
        return self.__query(query_string)


    def insert(self, table_name: str, data: tuple):
        '''Inserts a single row of data.'''
        if not table_name:
            print(
                'Error: Table name is required for SQLiteConnector::insert()',
                file=sys.stderr
            )
            return
        if not tuple:
            print(
                'Error: Non-empty tuple is required for '+
                'SQLiteConnector::insert()',
                file=sys.stderr
            )
            return

        # Example output: '?, ?, ?, ?, ?, ?, ?'
        question_string = ', '.join(len(data) * ['?'])
        
        query_string = "INSERT INTO " + table_name + \
            " VALUES(" + question_string + ");"

        print('SqliteConnector: Preparing to insert row ' + str(data))
        self.__query(query_string, data)

    def __query(self, query_string: str, data=()):
        '''Executes a query on the database and returns the SQLite result.'''
        print('SqliteConnector: Opening database connection to ' + self.__db_path)

        with closing(sqlite3.connect(self.__db_path)) as connection:
            with connection:  # Auto-commit
                with closing(connection.cursor()) as cursor:
                    if data is None:
                        result = cursor.execute(query_string)
                    result = cursor.execute(query_string, data).fetchall()

        print('SqliteConnector: Closing database connection to ' + self.__db_path)

        return result