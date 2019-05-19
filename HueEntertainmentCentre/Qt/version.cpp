#include <regex>

#include "version.h"

Version::Version()
{
}

Version::Version(const std::string &versionString)
{
	parse(versionString);
}

Version::Version(int major, int minor, int revision, int build)
{
	_major = major;
	_minor = minor;
	_revision = revision;
	_build = build;
}

Version Version::fromString(const std::string &versionString)
{
	return Version(versionString);
}

bool Version::valid()
{
	return getMajor() >= 0 && getMinor() >= 0 && getRevision() >= 0 && getBuild() >= 0;
}

bool Version::parse(const std::string & versionString)
{
	const std::regex versionFinder("([0-9]+)\\.([0-9]+)\\.([0-9]+)\\.([0-9]+)");
	std::smatch match;

	if (std::regex_search(versionString, match, versionFinder) && match.size() >= 5) {
		_major = std::stoi(match[1]);
		_minor = std::stoi(match[2]);
		_revision = std::stoi(match[3]);
		_build = std::stoi(match[4]);

		return valid();
	}

	return false;
}

int Version::getMajor() const
{
	return _major;
}

int Version::getMinor() const
{
	return _minor;
}

int Version::getRevision() const
{
	return _revision;
}

int Version::getBuild() const
{
	return _build;
}
