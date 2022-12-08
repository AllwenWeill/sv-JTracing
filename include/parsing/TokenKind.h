#ifndef TOKENKIND_H
#define TOKENKIND_H
#include "allinclude.h"

enum class TokenKind : std::uint16_t {
    Unknown,
    EndOfFile,
    Identifier,
    SystemIdentifier,
    StringLiteral, //�ַ���
    IntegerLiteral,
    IntegerBase,
    UnbasedUnsizedLiteral,
    RealLiteral,
    TimeLiteral,
    Placeholder,
    Apostrophe,
    ApostropheOpenBrace,
    OpenBrace,
    CloseBrace,
    OpenBracket,
    CloseBracket,
    OpenParenthesis,
    OpenParenthesisStar,
    CloseParenthesis,
    StarCloseParenthesis,
    Semicolon,
    Colon,
    ColonEquals,
    ColonSlash,
    DoubleColon,
    Comma,
    DotStar,
    Dot,
    Slash,
    Star,
    DoubleStar,
    StarArrow,
    Plus,
    DoublePlus,
    PlusColon,
    Minus,
    DoubleMinus,
    MinusColon,
    MinusArrow,
    MinusDoubleArrow,
    Tilde,
    TildeAnd,
    TildeOr,
    TildeXor,
    Dollar,
    Question,
    Hash,
    DoubleHash,
    HashMinusHash,
    HashEqualsHash,
    Xor,
    XorTilde,
    Equals,
    DoubleEquals,
    DoubleEqualsQuestion,
    TripleEquals,
    EqualsArrow,
    PlusEqual,
    MinusEqual,
    SlashEqual,
    StarEqual,
    AndEqual,
    OrEqual,
    PercentEqual,
    XorEqual,
    LeftShiftEqual,
    TripleLeftShiftEqual,
    RightShiftEqual,
    TripleRightShiftEqual,
    LeftShift,
    RightShift,
    TripleLeftShift,
    TripleRightShift,
    Exclamation,
    ExclamationEquals,
    ExclamationEqualsQuestion,
    ExclamationDoubleEquals,
    Percent,
    LessThan,
    LessThanEquals,
    LessThanMinusArrow,
    GreaterThan,
    GreaterThanEquals,
    Or, //|
    DoubleOr,
    OrMinusArrow,
    OrEqualsArrow,
    At,
    DoubleAt,
    And,
    DoubleAnd,
    TripleAnd,
    OneStep,
    AcceptOnKeyword,
    AliasKeyword,
    AlwaysKeyword,
    AlwaysCombKeyword,
    AlwaysFFKeyword,
    AlwaysLatchKeyword,
    AndKeyword,
    AssertKeyword,
    AssignKeyword,
    AssumeKeyword,
    AutomaticKeyword,
    BeforeKeyword,
    BeginKeyword,
    BindKeyword,
    BinsKeyword,
    BinsOfKeyword,
    BitKeyword,
    BreakKeyword,
    BufKeyword,
    BufIf0Keyword,
    BufIf1Keyword,
    ByteKeyword,
    CaseKeyword,
    CaseXKeyword,
    CaseZKeyword,
    CellKeyword,
    CHandleKeyword,
    CheckerKeyword,
    ClassKeyword,
    ClockingKeyword,
    CmosKeyword,
    ConfigKeyword,
    ConstKeyword,
    ConstraintKeyword,
    ContextKeyword,
    ContinueKeyword,
    CoverKeyword,
    CoverGroupKeyword,
    CoverPointKeyword,
    CrossKeyword,
    DeassignKeyword,
    DefaultKeyword,
    DefParamKeyword,
    DesignKeyword,
    DisableKeyword,
    DistKeyword,
    DoKeyword,
    EdgeKeyword,
    ElseKeyword,
    EndKeyword,
    EndCaseKeyword,
    EndCheckerKeyword,
    EndClassKeyword,
    EndClockingKeyword,
    EndConfigKeyword,
    EndFunctionKeyword,
    EndGenerateKeyword,
    EndGroupKeyword,
    EndInterfaceKeyword,
    EndModuleKeyword,
    EndPackageKeyword,
    EndPrimitiveKeyword,
    EndProgramKeyword,
    EndPropertyKeyword,
    EndSpecifyKeyword,
    EndSequenceKeyword,
    EndTableKeyword,
    EndTaskKeyword,
    EnumKeyword,
    EventKeyword,
    EventuallyKeyword,
    ExpectKeyword,
    ExportKeyword,
    ExtendsKeyword,
    ExternKeyword,
    FinalKeyword,
    FirstMatchKeyword,
    ForKeyword,
    ForceKeyword,
    ForeachKeyword,
    ForeverKeyword,
    ForkKeyword,
    ForkJoinKeyword,
    FunctionKeyword,
    GenerateKeyword,
    GenVarKeyword,
    GlobalKeyword,
    HighZ0Keyword,
    HighZ1Keyword,
    IfKeyword,
    IffKeyword,
    IfNoneKeyword,
    IgnoreBinsKeyword,
    IllegalBinsKeyword,
    ImplementsKeyword,
    ImpliesKeyword,
    ImportKeyword,
    IncDirKeyword,
    IncludeKeyword,
    InitialKeyword,
    InOutKeyword,
    InputKeyword,
    InsideKeyword,
    InstanceKeyword,
    IntKeyword,
    IntegerKeyword,
    InterconnectKeyword,
    InterfaceKeyword,
    IntersectKeyword,
    JoinKeyword,
    JoinAnyKeyword,
    JoinNoneKeyword,
    LargeKeyword,
    LetKeyword,
    LibListKeyword,
    LibraryKeyword,
    LocalKeyword,
    LocalParamKeyword,
    LogicKeyword,
    LongIntKeyword,
    MacromoduleKeyword,
    MatchesKeyword,
    MediumKeyword,
    ModPortKeyword,
    ModuleKeyword,
    NandKeyword,
    NegEdgeKeyword,
    NetTypeKeyword,
    NewKeyword,
    NextTimeKeyword,
    NmosKeyword,
    NorKeyword,
    NoShowCancelledKeyword,
    NotKeyword,
    NotIf0Keyword,
    NotIf1Keyword,
    NullKeyword,
    OrKeyword,
    OutputKeyword,
    PackageKeyword,
    PackedKeyword,
    ParameterKeyword,
    PmosKeyword,
    PosEdgeKeyword,
    PrimitiveKeyword,
    PriorityKeyword,
    ProgramKeyword,
    PropertyKeyword,
    ProtectedKeyword,
    Pull0Keyword,
    Pull1Keyword,
    PullDownKeyword,
    PullUpKeyword,
    PulseStyleOnDetectKeyword,
    PulseStyleOnEventKeyword,
    PureKeyword,
    RandKeyword,
    RandCKeyword,
    RandCaseKeyword,
    RandSequenceKeyword,
    RcmosKeyword,
    RealKeyword,
    RealTimeKeyword,
    RefKeyword,
    RegKeyword,
    RejectOnKeyword,
    ReleaseKeyword,
    RepeatKeyword,
    RestrictKeyword,
    ReturnKeyword,
    RnmosKeyword,
    RpmosKeyword,
    RtranKeyword,
    RtranIf0Keyword,
    RtranIf1Keyword,
    SAlwaysKeyword,
    SEventuallyKeyword,
    SNextTimeKeyword,
    SUntilKeyword,
    SUntilWithKeyword,
    ScalaredKeyword,
    SequenceKeyword,
    ShortIntKeyword,
    ShortRealKeyword,
    ShowCancelledKeyword,
    SignedKeyword,
    SmallKeyword,
    SoftKeyword,
    SolveKeyword,
    SpecifyKeyword,
    SpecParamKeyword,
    StaticKeyword,
    StringKeyword,
    StrongKeyword,
    Strong0Keyword,
    Strong1Keyword,
    StructKeyword,
    SuperKeyword,
    Supply0Keyword,
    Supply1Keyword,
    SyncAcceptOnKeyword,
    SyncRejectOnKeyword,
    TableKeyword,
    TaggedKeyword,
    TaskKeyword,
    ThisKeyword,
    ThroughoutKeyword,
    TimeKeyword,
    TimePrecisionKeyword,
    TimeUnitKeyword,
    TranKeyword,
    TranIf0Keyword,
    TranIf1Keyword,
    TriKeyword,
    Tri0Keyword,
    Tri1Keyword,
    TriAndKeyword,
    TriOrKeyword,
    TriRegKeyword,
    TypeKeyword,
    TypedefKeyword,
    UnionKeyword,
    UniqueKeyword,
    Unique0Keyword,
    UnsignedKeyword,
    UntilKeyword,
    UntilWithKeyword,
    UntypedKeyword,
    UseKeyword,
    UWireKeyword,
    VarKeyword,
    VectoredKeyword,
    VirtualKeyword,
    VoidKeyword,
    WaitKeyword,
    WaitOrderKeyword,
    WAndKeyword,
    WeakKeyword,
    Weak0Keyword,
    Weak1Keyword,
    WhileKeyword,
    WildcardKeyword,
    WireKeyword,
    WithKeyword,
    WithinKeyword,
    WOrKeyword,
    XnorKeyword,
    XorKeyword,
    DefineKeyword,
    UnitSystemName,
    RootSystemName,
    Directive,
    IncludeFileName,
    MacroUsage,
    MacroQuote,
    MacroEscapedQuote,
    MacroPaste,
    EmptyMacroArgument,
    LineContinuation,
};

string TokenKindtoString(TokenKind kind) {
    switch (kind) {
    case TokenKind::Unknown: return "Unknown";
    case TokenKind::EndOfFile: return "EndOfFile";
    case TokenKind::Identifier: return "Identifier";
    case TokenKind::SystemIdentifier: return "SystemIdentifier";
    case TokenKind::StringLiteral: return "StringLiteral";
    case TokenKind::IntegerLiteral: return "IntegerLiteral";
    case TokenKind::IntegerBase: return "IntegerBase";
    case TokenKind::UnbasedUnsizedLiteral: return "UnbasedUnsizedLiteral";
    case TokenKind::RealLiteral: return "RealLiteral";
    case TokenKind::TimeLiteral: return "TimeLiteral";
    case TokenKind::Placeholder: return "Placeholder";
    case TokenKind::Apostrophe: return "Apostrophe";
    case TokenKind::ApostropheOpenBrace: return "ApostropheOpenBrace";
    case TokenKind::OpenBrace: return "OpenBrace";
    case TokenKind::CloseBrace: return "CloseBrace";
    case TokenKind::OpenBracket: return "OpenBracket";
    case TokenKind::CloseBracket: return "CloseBracket";
    case TokenKind::OpenParenthesis: return "OpenParenthesis";
    case TokenKind::OpenParenthesisStar: return "OpenParenthesisStar";
    case TokenKind::CloseParenthesis: return "CloseParenthesis";
    case TokenKind::StarCloseParenthesis: return "StarCloseParenthesis";
    case TokenKind::Semicolon: return "Semicolon";
    case TokenKind::Colon: return "Colon";
    case TokenKind::ColonEquals: return "ColonEquals";
    case TokenKind::ColonSlash: return "ColonSlash";
    case TokenKind::DoubleColon: return "DoubleColon";
    case TokenKind::Comma: return "Comma";
    case TokenKind::DotStar: return "DotStar";
    case TokenKind::Dot: return "Dot";
    case TokenKind::Slash: return "Slash";
    case TokenKind::Star: return "Star";
    case TokenKind::DoubleStar: return "DoubleStar";
    case TokenKind::StarArrow: return "StarArrow";
    case TokenKind::Plus: return "Plus";
    case TokenKind::DoublePlus: return "DoublePlus";
    case TokenKind::PlusColon: return "PlusColon";
    case TokenKind::Minus: return "Minus";
    case TokenKind::DoubleMinus: return "DoubleMinus";
    case TokenKind::MinusColon: return "MinusColon";
    case TokenKind::MinusArrow: return "MinusArrow";
    case TokenKind::MinusDoubleArrow: return "MinusDoubleArrow";
    case TokenKind::Tilde: return "Tilde";
    case TokenKind::TildeAnd: return "TildeAnd";
    case TokenKind::TildeOr: return "TildeOr";
    case TokenKind::TildeXor: return "TildeXor";
    case TokenKind::Dollar: return "Dollar";
    case TokenKind::Question: return "Question";
    case TokenKind::Hash: return "Hash";
    case TokenKind::DoubleHash: return "DoubleHash";
    case TokenKind::HashMinusHash: return "HashMinusHash";
    case TokenKind::HashEqualsHash: return "HashEqualsHash";
    case TokenKind::Xor: return "Xor";
    case TokenKind::XorTilde: return "XorTilde";
    case TokenKind::Equals: return "Equals";
    case TokenKind::DoubleEquals: return "DoubleEquals";
    case TokenKind::DoubleEqualsQuestion: return "DoubleEqualsQuestion";
    case TokenKind::TripleEquals: return "TripleEquals";
    case TokenKind::EqualsArrow: return "EqualsArrow";
    case TokenKind::PlusEqual: return "PlusEqual";
    case TokenKind::MinusEqual: return "MinusEqual";
    case TokenKind::SlashEqual: return "SlashEqual";
    case TokenKind::StarEqual: return "StarEqual";
    case TokenKind::AndEqual: return "AndEqual";
    case TokenKind::OrEqual: return "OrEqual";
    case TokenKind::PercentEqual: return "PercentEqual";
    case TokenKind::XorEqual: return "XorEqual";
    case TokenKind::LeftShiftEqual: return "LeftShiftEqual";
    case TokenKind::TripleLeftShiftEqual: return "TripleLeftShiftEqual";
    case TokenKind::RightShiftEqual: return "RightShiftEqual";
    case TokenKind::TripleRightShiftEqual: return "TripleRightShiftEqual";
    case TokenKind::LeftShift: return "LeftShift";
    case TokenKind::RightShift: return "RightShift";
    case TokenKind::TripleLeftShift: return "TripleLeftShift";
    case TokenKind::TripleRightShift: return "TripleRightShift";
    case TokenKind::Exclamation: return "Exclamation";
    case TokenKind::ExclamationEquals: return "ExclamationEquals";
    case TokenKind::ExclamationEqualsQuestion: return "ExclamationEqualsQuestion";
    case TokenKind::ExclamationDoubleEquals: return "ExclamationDoubleEquals";
    case TokenKind::Percent: return "Percent";
    case TokenKind::LessThan: return "LessThan";
    case TokenKind::LessThanEquals: return "LessThanEquals";
    case TokenKind::LessThanMinusArrow: return "LessThanMinusArrow";
    case TokenKind::GreaterThan: return "GreaterThan";
    case TokenKind::GreaterThanEquals: return "GreaterThanEquals";
    case TokenKind::Or: return "Or";
    case TokenKind::DoubleOr: return "DoubleOr";
    case TokenKind::OrMinusArrow: return "OrMinusArrow";
    case TokenKind::OrEqualsArrow: return "OrEqualsArrow";
    case TokenKind::At: return "At";
    case TokenKind::DoubleAt: return "DoubleAt";
    case TokenKind::And: return "And";
    case TokenKind::DoubleAnd: return "DoubleAnd";
    case TokenKind::TripleAnd: return "TripleAnd";
    case TokenKind::OneStep: return "OneStep";
    case TokenKind::AcceptOnKeyword: return "AcceptOnKeyword";
    case TokenKind::AliasKeyword: return "AliasKeyword";
    case TokenKind::AlwaysKeyword: return "AlwaysKeyword";
    case TokenKind::AlwaysCombKeyword: return "AlwaysCombKeyword";
    case TokenKind::AlwaysFFKeyword: return "AlwaysFFKeyword";
    case TokenKind::AlwaysLatchKeyword: return "AlwaysLatchKeyword";
    case TokenKind::AndKeyword: return "AndKeyword";
    case TokenKind::AssertKeyword: return "AssertKeyword";
    case TokenKind::AssignKeyword: return "AssignKeyword";
    case TokenKind::AssumeKeyword: return "AssumeKeyword";
    case TokenKind::AutomaticKeyword: return "AutomaticKeyword";
    case TokenKind::BeforeKeyword: return "BeforeKeyword";
    case TokenKind::BeginKeyword: return "BeginKeyword";
    case TokenKind::BindKeyword: return "BindKeyword";
    case TokenKind::BinsKeyword: return "BinsKeyword";
    case TokenKind::BinsOfKeyword: return "BinsOfKeyword";
    case TokenKind::BitKeyword: return "BitKeyword";
    case TokenKind::BreakKeyword: return "BreakKeyword";
    case TokenKind::BufKeyword: return "BufKeyword";
    case TokenKind::BufIf0Keyword: return "BufIf0Keyword";
    case TokenKind::BufIf1Keyword: return "BufIf1Keyword";
    case TokenKind::ByteKeyword: return "ByteKeyword";
    case TokenKind::CaseKeyword: return "CaseKeyword";
    case TokenKind::CaseXKeyword: return "CaseXKeyword";
    case TokenKind::CaseZKeyword: return "CaseZKeyword";
    case TokenKind::CellKeyword: return "CellKeyword";
    case TokenKind::CHandleKeyword: return "CHandleKeyword";
    case TokenKind::CheckerKeyword: return "CheckerKeyword";
    case TokenKind::ClassKeyword: return "ClassKeyword";
    case TokenKind::ClockingKeyword: return "ClockingKeyword";
    case TokenKind::CmosKeyword: return "CmosKeyword";
    case TokenKind::ConfigKeyword: return "ConfigKeyword";
    case TokenKind::ConstKeyword: return "ConstKeyword";
    case TokenKind::ConstraintKeyword: return "ConstraintKeyword";
    case TokenKind::ContextKeyword: return "ContextKeyword";
    case TokenKind::ContinueKeyword: return "ContinueKeyword";
    case TokenKind::CoverKeyword: return "CoverKeyword";
    case TokenKind::CoverGroupKeyword: return "CoverGroupKeyword";
    case TokenKind::CoverPointKeyword: return "CoverPointKeyword";
    case TokenKind::CrossKeyword: return "CrossKeyword";
    case TokenKind::DeassignKeyword: return "DeassignKeyword";
    case TokenKind::DefaultKeyword: return "DefaultKeyword";
    case TokenKind::DefParamKeyword: return "DefParamKeyword";
    case TokenKind::DesignKeyword: return "DesignKeyword";
    case TokenKind::DisableKeyword: return "DisableKeyword";
    case TokenKind::DistKeyword: return "DistKeyword";
    case TokenKind::DoKeyword: return "DoKeyword";
    case TokenKind::EdgeKeyword: return "EdgeKeyword";
    case TokenKind::ElseKeyword: return "ElseKeyword";
    case TokenKind::EndKeyword: return "EndKeyword";
    case TokenKind::EndCaseKeyword: return "EndCaseKeyword";
    case TokenKind::EndCheckerKeyword: return "EndCheckerKeyword";
    case TokenKind::EndClassKeyword: return "EndClassKeyword";
    case TokenKind::EndClockingKeyword: return "EndClockingKeyword";
    case TokenKind::EndConfigKeyword: return "EndConfigKeyword";
    case TokenKind::EndFunctionKeyword: return "EndFunctionKeyword";
    case TokenKind::EndGenerateKeyword: return "EndGenerateKeyword";
    case TokenKind::EndGroupKeyword: return "EndGroupKeyword";
    case TokenKind::EndInterfaceKeyword: return "EndInterfaceKeyword";
    case TokenKind::EndModuleKeyword: return "EndModuleKeyword";
    case TokenKind::EndPackageKeyword: return "EndPackageKeyword";
    case TokenKind::EndPrimitiveKeyword: return "EndPrimitiveKeyword";
    case TokenKind::EndProgramKeyword: return "EndProgramKeyword";
    case TokenKind::EndPropertyKeyword: return "EndPropertyKeyword";
    case TokenKind::EndSpecifyKeyword: return "EndSpecifyKeyword";
    case TokenKind::EndSequenceKeyword: return "EndSequenceKeyword";
    case TokenKind::EndTableKeyword: return "EndTableKeyword";
    case TokenKind::EndTaskKeyword: return "EndTaskKeyword";
    case TokenKind::EnumKeyword: return "EnumKeyword";
    case TokenKind::EventKeyword: return "EventKeyword";
    case TokenKind::EventuallyKeyword: return "EventuallyKeyword";
    case TokenKind::ExpectKeyword: return "ExpectKeyword";
    case TokenKind::ExportKeyword: return "ExportKeyword";
    case TokenKind::ExtendsKeyword: return "ExtendsKeyword";
    case TokenKind::ExternKeyword: return "ExternKeyword";
    case TokenKind::FinalKeyword: return "FinalKeyword";
    case TokenKind::FirstMatchKeyword: return "FirstMatchKeyword";
    case TokenKind::ForKeyword: return "ForKeyword";
    case TokenKind::ForceKeyword: return "ForceKeyword";
    case TokenKind::ForeachKeyword: return "ForeachKeyword";
    case TokenKind::ForeverKeyword: return "ForeverKeyword";
    case TokenKind::ForkKeyword: return "ForkKeyword";
    case TokenKind::ForkJoinKeyword: return "ForkJoinKeyword";
    case TokenKind::FunctionKeyword: return "FunctionKeyword";
    case TokenKind::GenerateKeyword: return "GenerateKeyword";
    case TokenKind::GenVarKeyword: return "GenVarKeyword";
    case TokenKind::GlobalKeyword: return "GlobalKeyword";
    case TokenKind::HighZ0Keyword: return "HighZ0Keyword";
    case TokenKind::HighZ1Keyword: return "HighZ1Keyword";
    case TokenKind::IfKeyword: return "IfKeyword";
    case TokenKind::IffKeyword: return "IffKeyword";
    case TokenKind::IfNoneKeyword: return "IfNoneKeyword";
    case TokenKind::IgnoreBinsKeyword: return "IgnoreBinsKeyword";
    case TokenKind::IllegalBinsKeyword: return "IllegalBinsKeyword";
    case TokenKind::ImplementsKeyword: return "ImplementsKeyword";
    case TokenKind::ImpliesKeyword: return "ImpliesKeyword";
    case TokenKind::ImportKeyword: return "ImportKeyword";
    case TokenKind::IncDirKeyword: return "IncDirKeyword";
    case TokenKind::IncludeKeyword: return "IncludeKeyword";
    case TokenKind::InitialKeyword: return "InitialKeyword";
    case TokenKind::InOutKeyword: return "InOutKeyword";
    case TokenKind::InputKeyword: return "InputKeyword";
    case TokenKind::InsideKeyword: return "InsideKeyword";
    case TokenKind::InstanceKeyword: return "InstanceKeyword";
    case TokenKind::IntKeyword: return "IntKeyword";
    case TokenKind::IntegerKeyword: return "IntegerKeyword";
    case TokenKind::InterconnectKeyword: return "InterconnectKeyword";
    case TokenKind::InterfaceKeyword: return "InterfaceKeyword";
    case TokenKind::IntersectKeyword: return "IntersectKeyword";
    case TokenKind::JoinKeyword: return "JoinKeyword";
    case TokenKind::JoinAnyKeyword: return "JoinAnyKeyword";
    case TokenKind::JoinNoneKeyword: return "JoinNoneKeyword";
    case TokenKind::LargeKeyword: return "LargeKeyword";
    case TokenKind::LetKeyword: return "LetKeyword";
    case TokenKind::LibListKeyword: return "LibListKeyword";
    case TokenKind::LibraryKeyword: return "LibraryKeyword";
    case TokenKind::LocalKeyword: return "LocalKeyword";
    case TokenKind::LocalParamKeyword: return "LocalParamKeyword";
    case TokenKind::LogicKeyword: return "LogicKeyword";
    case TokenKind::LongIntKeyword: return "LongIntKeyword";
    case TokenKind::MacromoduleKeyword: return "MacromoduleKeyword";
    case TokenKind::MatchesKeyword: return "MatchesKeyword";
    case TokenKind::MediumKeyword: return "MediumKeyword";
    case TokenKind::ModPortKeyword: return "ModPortKeyword";
    case TokenKind::ModuleKeyword: return "ModuleKeyword";
    case TokenKind::NandKeyword: return "NandKeyword";
    case TokenKind::NegEdgeKeyword: return "NegEdgeKeyword";
    case TokenKind::NetTypeKeyword: return "NetTypeKeyword";
    case TokenKind::NewKeyword: return "NewKeyword";
    case TokenKind::NextTimeKeyword: return "NextTimeKeyword";
    case TokenKind::NmosKeyword: return "NmosKeyword";
    case TokenKind::NorKeyword: return "NorKeyword";
    case TokenKind::NoShowCancelledKeyword: return "NoShowCancelledKeyword";
    case TokenKind::NotKeyword: return "NotKeyword";
    case TokenKind::NotIf0Keyword: return "NotIf0Keyword";
    case TokenKind::NotIf1Keyword: return "NotIf1Keyword";
    case TokenKind::NullKeyword: return "NullKeyword";
    case TokenKind::OrKeyword: return "OrKeyword";
    case TokenKind::OutputKeyword: return "OutputKeyword";
    case TokenKind::PackageKeyword: return "PackageKeyword";
    case TokenKind::PackedKeyword: return "PackedKeyword";
    case TokenKind::ParameterKeyword: return "ParameterKeyword";
    case TokenKind::PmosKeyword: return "PmosKeyword";
    case TokenKind::PosEdgeKeyword: return "PosEdgeKeyword";
    case TokenKind::PrimitiveKeyword: return "PrimitiveKeyword";
    case TokenKind::PriorityKeyword: return "PriorityKeyword";
    case TokenKind::ProgramKeyword: return "ProgramKeyword";
    case TokenKind::PropertyKeyword: return "PropertyKeyword";
    case TokenKind::ProtectedKeyword: return "ProtectedKeyword";
    case TokenKind::Pull0Keyword: return "Pull0Keyword";
    case TokenKind::Pull1Keyword: return "Pull1Keyword";
    case TokenKind::PullDownKeyword: return "PullDownKeyword";
    case TokenKind::PullUpKeyword: return "PullUpKeyword";
    case TokenKind::PulseStyleOnDetectKeyword: return "PulseStyleOnDetectKeyword";
    case TokenKind::PulseStyleOnEventKeyword: return "PulseStyleOnEventKeyword";
    case TokenKind::PureKeyword: return "PureKeyword";
    case TokenKind::RandKeyword: return "RandKeyword";
    case TokenKind::RandCKeyword: return "RandCKeyword";
    case TokenKind::RandCaseKeyword: return "RandCaseKeyword";
    case TokenKind::RandSequenceKeyword: return "RandSequenceKeyword";
    case TokenKind::RcmosKeyword: return "RcmosKeyword";
    case TokenKind::RealKeyword: return "RealKeyword";
    case TokenKind::RealTimeKeyword: return "RealTimeKeyword";
    case TokenKind::RefKeyword: return "RefKeyword";
    case TokenKind::RegKeyword: return "RegKeyword";
    case TokenKind::RejectOnKeyword: return "RejectOnKeyword";
    case TokenKind::ReleaseKeyword: return "ReleaseKeyword";
    case TokenKind::RepeatKeyword: return "RepeatKeyword";
    case TokenKind::RestrictKeyword: return "RestrictKeyword";
    case TokenKind::ReturnKeyword: return "ReturnKeyword";
    case TokenKind::RnmosKeyword: return "RnmosKeyword";
    case TokenKind::RpmosKeyword: return "RpmosKeyword";
    case TokenKind::RtranKeyword: return "RtranKeyword";
    case TokenKind::RtranIf0Keyword: return "RtranIf0Keyword";
    case TokenKind::RtranIf1Keyword: return "RtranIf1Keyword";
    case TokenKind::SAlwaysKeyword: return "SAlwaysKeyword";
    case TokenKind::SEventuallyKeyword: return "SEventuallyKeyword";
    case TokenKind::SNextTimeKeyword: return "SNextTimeKeyword";
    case TokenKind::SUntilKeyword: return "SUntilKeyword";
    case TokenKind::SUntilWithKeyword: return "SUntilWithKeyword";
    case TokenKind::ScalaredKeyword: return "ScalaredKeyword";
    case TokenKind::SequenceKeyword: return "SequenceKeyword";
    case TokenKind::ShortIntKeyword: return "ShortIntKeyword";
    case TokenKind::ShortRealKeyword: return "ShortRealKeyword";
    case TokenKind::ShowCancelledKeyword: return "ShowCancelledKeyword";
    case TokenKind::SignedKeyword: return "SignedKeyword";
    case TokenKind::SmallKeyword: return "SmallKeyword";
    case TokenKind::SoftKeyword: return "SoftKeyword";
    case TokenKind::SolveKeyword: return "SolveKeyword";
    case TokenKind::SpecifyKeyword: return "SpecifyKeyword";
    case TokenKind::SpecParamKeyword: return "SpecParamKeyword";
    case TokenKind::StaticKeyword: return "StaticKeyword";
    case TokenKind::StringKeyword: return "StringKeyword";
    case TokenKind::StrongKeyword: return "StrongKeyword";
    case TokenKind::Strong0Keyword: return "Strong0Keyword";
    case TokenKind::Strong1Keyword: return "Strong1Keyword";
    case TokenKind::StructKeyword: return "StructKeyword";
    case TokenKind::SuperKeyword: return "SuperKeyword";
    case TokenKind::Supply0Keyword: return "Supply0Keyword";
    case TokenKind::Supply1Keyword: return "Supply1Keyword";
    case TokenKind::SyncAcceptOnKeyword: return "SyncAcceptOnKeyword";
    case TokenKind::SyncRejectOnKeyword: return "SyncRejectOnKeyword";
    case TokenKind::TableKeyword: return "TableKeyword";
    case TokenKind::TaggedKeyword: return "TaggedKeyword";
    case TokenKind::TaskKeyword: return "TaskKeyword";
    case TokenKind::ThisKeyword: return "ThisKeyword";
    case TokenKind::ThroughoutKeyword: return "ThroughoutKeyword";
    case TokenKind::TimeKeyword: return "TimeKeyword";
    case TokenKind::TimePrecisionKeyword: return "TimePrecisionKeyword";
    case TokenKind::TimeUnitKeyword: return "TimeUnitKeyword";
    case TokenKind::TranKeyword: return "TranKeyword";
    case TokenKind::TranIf0Keyword: return "TranIf0Keyword";
    case TokenKind::TranIf1Keyword: return "TranIf1Keyword";
    case TokenKind::TriKeyword: return "TriKeyword";
    case TokenKind::Tri0Keyword: return "Tri0Keyword";
    case TokenKind::Tri1Keyword: return "Tri1Keyword";
    case TokenKind::TriAndKeyword: return "TriAndKeyword";
    case TokenKind::TriOrKeyword: return "TriOrKeyword";
    case TokenKind::TriRegKeyword: return "TriRegKeyword";
    case TokenKind::TypeKeyword: return "TypeKeyword";
    case TokenKind::TypedefKeyword: return "TypedefKeyword";
    case TokenKind::UnionKeyword: return "UnionKeyword";
    case TokenKind::UniqueKeyword: return "UniqueKeyword";
    case TokenKind::Unique0Keyword: return "Unique0Keyword";
    case TokenKind::UnsignedKeyword: return "UnsignedKeyword";
    case TokenKind::UntilKeyword: return "UntilKeyword";
    case TokenKind::UntilWithKeyword: return "UntilWithKeyword";
    case TokenKind::UntypedKeyword: return "UntypedKeyword";
    case TokenKind::UseKeyword: return "UseKeyword";
    case TokenKind::UWireKeyword: return "UWireKeyword";
    case TokenKind::VarKeyword: return "VarKeyword";
    case TokenKind::VectoredKeyword: return "VectoredKeyword";
    case TokenKind::VirtualKeyword: return "VirtualKeyword";
    case TokenKind::VoidKeyword: return "VoidKeyword";
    case TokenKind::WaitKeyword: return "WaitKeyword";
    case TokenKind::WaitOrderKeyword: return "WaitOrderKeyword";
    case TokenKind::WAndKeyword: return "WAndKeyword";
    case TokenKind::WeakKeyword: return "WeakKeyword";
    case TokenKind::Weak0Keyword: return "Weak0Keyword";
    case TokenKind::Weak1Keyword: return "Weak1Keyword";
    case TokenKind::WhileKeyword: return "WhileKeyword";
    case TokenKind::WildcardKeyword: return "WildcardKeyword";
    case TokenKind::WireKeyword: return "WireKeyword";
    case TokenKind::WithKeyword: return "WithKeyword";
    case TokenKind::WithinKeyword: return "WithinKeyword";
    case TokenKind::WOrKeyword: return "WOrKeyword";
    case TokenKind::XnorKeyword: return "XnorKeyword";
    case TokenKind::XorKeyword: return "XorKeyword";
    case TokenKind::UnitSystemName: return "UnitSystemName";
    case TokenKind::RootSystemName: return "RootSystemName";
    case TokenKind::Directive: return "Directive";
    case TokenKind::IncludeFileName: return "IncludeFileName";
    case TokenKind::MacroUsage: return "MacroUsage";
    case TokenKind::MacroQuote: return "MacroQuote";
    case TokenKind::MacroEscapedQuote: return "MacroEscapedQuote";
    case TokenKind::MacroPaste: return "MacroPaste";
    case TokenKind::EmptyMacroArgument: return "EmptyMacroArgument";
    case TokenKind::LineContinuation: return "LineContinuation";
    default: return "";
    }
}
#endif