
#include "dirtraverser.h"

#include <QDir>
#include <QFile>
#include <QDirIterator>

DirTraverser::DirTraverser()
{
}

DirTraverser::~DirTraverser()
{
	foreach( AbstractDirTraverserFilter* filter, filters )
	{
		delete filter;
	}
	filters.clear();
}

void DirTraverser::copyDir( const QString& src, const QString& dest )
{
	//Check whether the dir directory exists
	if( QDir( src ).exists() ) 
	{
		if( !QDir( dest ).exists() ) 
			QDir().mkpath( dest );

		//Construct an iterator to get the entries in the directory
		QDirIterator dirIterator( src, QDir::AllEntries | QDir::NoDotAndDotDot );
		while ( dirIterator.hasNext() ) 
		{
			QString item = dirIterator.next();
			QString fileName = dirIterator.fileName();
			QFileInfo fileInfo = dirIterator.fileInfo();

			if ( checkExclusionList(fileInfo.absoluteFilePath()) )
				continue;

			//If entry is a file copy it
			if ( fileInfo.isFile() )
			{
				QFile::copy(item, dest + "/" + fileName);
				runFilters( dest + "/" + fileName );
			}
			else
				copyDir( item, dest + "/" + fileName );
		}
	}
	else
	{
		qWarning( qPrintable(QString("DirTraverser::copyDir - src folder [%1] doesn't exist").arg(src)) );
	}
}

void DirTraverser::run( const QString& src, const QString& dest )
{
	copyDir(src, dest);
}

void DirTraverser::runFilters( const QString& fileName )
{
	foreach( AbstractDirTraverserFilter* filter, filters )
	{
		if ( !filter->onFile( fileName ) )
			break;
	}
}

void DirTraverser::addExclusion( const QRegExp& e )
{
	excludeList.append( e );
}

/*!
	Returns true if \a file matches an exclusion list entry
*/
bool DirTraverser::checkExclusionList( const QString& file )
{
	foreach( QRegExp pattern, excludeList )
	{
		if ( pattern.exactMatch(file) )
			return true;
	}
	return false;
}
