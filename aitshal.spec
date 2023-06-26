Name:           aitshal
Version:        0.0.1
Release:        1%{?dist}
Summary:        A command-line tool to download B-Consortium projects
Group:          Development/Tools
License:        B-License
URL:            https://github.com/B-Consortium/aitshal
Source0: 	https://github.com/B-Consortium/aitshal/archive/v%{version}.tar.gz
BuildRoot:      %(mktemp -ud %{_tmppath}/%{name}-%{version}-%{release}-XXXXXX)
BuildRequires:  ncurses-devel

%description
This command-line tool is used to build and load C-styled projects without hussle of running the commands on Linux always

%prep
%setup -q -n %{name}-%{version}

%build
make aitshal

%install
install -d m0755 %{buildroot}%{_bindir}
make install prefix=%{buildroot}/usr

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root,-)
%{_bindir}/aitshal
%{_mandir}/man6/aitshal.6%{ext_man}
