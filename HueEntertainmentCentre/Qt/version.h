#pragma once

#include <string>

class Version
{
public:
	Version();
	Version(const std::string &versionString);
	Version(int major, int minor, int revision, int build);

	static Version fromString(const std::string &versionString);

	bool valid();
	bool parse(const std::string &versionString);

	int getMajor() const;
	int getMinor() const;
	int getRevision() const;
	int getBuild() const;

	bool operator==(const Version &other) const { return getMajor() == other.getMajor() && getMinor() == other.getMinor() && getRevision() == other.getRevision() && getBuild() == other.getBuild(); };
	bool operator!=(const Version &other) const { return *this != other; };
	bool operator<(const Version &other) const { return getMajor() < other.getMajor() || (getMajor() == other.getMajor() && getMinor() < other.getMinor()) || (getMajor() == other.getMajor() && getMinor() == other.getMinor() && getRevision() < other.getRevision()); };
	bool operator<=(const Version &other) const { return *this == other || *this < other; };
	bool operator>(const Version &other) const { return !(*this <= other); };
	bool operator>=(const Version &other) const { return !(*this < other); };

private:
	int _major = -1;
	int _minor = -1;
	int _revision = -1;
	int _build = -1;
};