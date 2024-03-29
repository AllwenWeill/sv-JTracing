#ifndef SYNTAXKIND_H
#define SYNTAXKIND_H
#include "allinclude.h"
enum class SyntaxKind {
    Unknown,
    SyntaxList,
    TokenList,
    SeparatedList,
    AcceptOnPropertyExpr,
    ActionBlock,
    AddAssignmentExpression,
    AddExpression,
    AlwaysBlock,
    AlwaysCombBlock,
    AlwaysFFBlock,
    AlwaysLatchBlock,
    AndAssignmentExpression,
    AndPropertyExpr,
    AndSequenceExpr,
    AnsiPortList,
    AnsiUdpPortList,
    ArgumentList,
    ArithmeticLeftShiftAssignmentExpression,
    ArithmeticRightShiftAssignmentExpression,
    ArithmeticShiftLeftExpression,
    ArithmeticShiftRightExpression,
    ArrayAndMethod,
    ArrayOrMethod,
    ArrayOrRandomizeMethodExpression,
    ArrayUniqueMethod,
    ArrayXorMethod,
    AscendingRangeSelect,
    AssertPropertyStatement,
    AssertionItemPort,
    AssertionItemPortList,
    AssignmentExpression,
    AssignmentPatternExpression,
    AssignmentPatternItem,
    AssumePropertyStatement,
    AttributeInstance,
    AttributeSpec,
    BadExpression,
    BeginKeywordsDirective,
    BinSelectWithFilterExpr,
    BinaryAndExpression,
    BinaryBinsSelectExpr,
    BinaryBlockEventExpression,
    BinaryEventExpression,
    BinaryOrExpression,
    BinaryXnorExpression,
    BinaryXorExpression,
    BindDirective,
    BindTargetList,
    BinsSelectConditionExpr,
    BinsSelection,
    BitSelect,
    BitType,
    BlockCoverageEvent,
    BlockingEventTriggerStatement,
    ByteType,
    CHandleType,
    CaseEqualityExpression,
    CaseGenerate,
    CaseInequalityExpression,
    CasePropertyExpr,
    CaseStatement,
    CastExpression,
    CellConfigRule,
    CellDefineDirective,
    ChargeStrength,
    CheckerDataDeclaration,
    CheckerDeclaration,
    CheckerInstanceStatement,
    CheckerInstantiation,
    ClassDeclaration,
    ClassMethodDeclaration,
    ClassMethodPrototype,
    ClassName,
    ClassPropertyDeclaration,
    ClockingDeclaration,
    ClockingDirection,
    ClockingItem,
    ClockingPropertyExpr,
    ClockingSequenceExpr,
    ClockingSkew,
    ColonExpressionClause,
    CompilationUnit,
    ConcatenationExpression,
    ConcurrentAssertionMember,
    ConditionalConstraint,
    ConditionalExpression,
    ConditionalPathDeclaration,
    ConditionalPattern,
    ConditionalPredicate,
    ConditionalPropertyExpr,
    ConditionalStatement,
    ConfigCellIdentifier,
    ConfigDeclaration,
    ConfigInstanceIdentifier,
    ConfigLiblist,
    ConfigUseClause,
    ConstraintBlock,
    ConstraintDeclaration,
    ConstraintPrototype,
    ConstructorName,
    ContinuousAssign,
    CopyClassExpression,
    CoverCross,
    CoverPropertyStatement,
    CoverSequenceStatement,
    CoverageBins,
    CoverageBinsArraySize,
    CoverageIffClause,
    CoverageOption,
    CovergroupDeclaration,
    Coverpoint,
    CycleDelay,
    DPIExport,
    DPIImport,
    DataDeclaration,
    Declarator,
    DefParam,
    DefParamAssignment,
    DefaultCaseItem,
    DefaultClockingReference,
    DefaultConfigRule,
    DefaultCoverageBinInitializer,
    DefaultDisableDeclaration,
    DefaultNetTypeDirective,
    DefaultPatternKeyExpression,
    DefaultPropertyCaseItem,
    DefaultRsCaseItem,
    DefaultSkewItem,
    DeferredAssertion,
    DefineDirective,
    Delay3,
    DelayControl,
    DelayedSequenceElement,
    DelayedSequenceExpr,
    DelayedTerminalArg,
    DescendingRangeSelect,
    DisableConstraint,
    DisableForkStatement,
    DisableIff,
    DisableStatement,
    DistConstraintList,
    DistItem,
    DistWeight,
    DivideAssignmentExpression,
    DivideExpression,
    DividerClause,
    DoWhileStatement,
    DotMemberClause,
    DriveStrength,
    EdgeControlSpecifier,
    EdgeDescriptor,
    EdgeSensitivePathSuffix,
    ElabSystemTask,
    ElementSelect,
    ElementSelectExpression,
    ElsIfDirective,
    ElseClause,
    ElseConstraintClause,
    ElseDirective,
    ElsePropertyClause,
    EmptyArgument,
    EmptyIdentifierName,
    EmptyMember,
    EmptyNonAnsiPort,
    EmptyPortConnection,
    EmptyQueueExpression,
    EmptyStatement,
    EmptyTimingCheckArg,
    EndCellDefineDirective,
    EndIfDirective,
    EndKeywordsDirective,
    EnumType,
    EqualityExpression,
    EqualsAssertionArgClause,
    EqualsTypeClause,
    EqualsValueClause,
    EventControl,
    EventControlWithExpression,
    EventType,
    ExpectPropertyStatement,
    ExplicitAnsiPort,
    ExplicitNonAnsiPort,
    ExpressionConstraint,
    ExpressionCoverageBinInitializer,
    ExpressionOrDist,
    ExpressionPattern,
    ExpressionStatement,
    ExpressionTimingCheckArg,
    ExtendsClause,
    ExternInterfaceMethod,
    ExternModuleDecl,
    ExternUdpDecl,
    FinalBlock,
    FirstMatchSequenceExpr,
    FollowedByPropertyExpr,
    ForLoopStatement,
    ForVariableDeclaration,
    ForeachLoopList,
    ForeachLoopStatement,
    ForeverStatement,
    ForwardInterfaceClassTypedefDeclaration,
    ForwardTypedefDeclaration,
    FunctionDeclaration,
    FunctionPort,
    FunctionPortList,
    FunctionPrototype,
    GenerateBlock,
    GenerateRegion,
    GenvarDeclaration,
    GreaterThanEqualExpression,
    GreaterThanExpression,
    HierarchicalInstance,
    HierarchyInstantiation,
    IdWithExprCoverageBinInitializer,
    IdentifierName,
    IdentifierSelectName,
    IfDefDirective,
    IfGenerate,
    IfNDefDirective,
    IfNonePathDeclaration,
    IffEventClause,
    IffPropertyExpr,
    ImmediateAssertStatement,
    ImmediateAssertionMember,
    ImmediateAssumeStatement,
    ImmediateCoverStatement,
    ImplementsClause,
    ImplicationConstraint,
    ImplicationPropertyExpr,
    ImplicitAnsiPort,
    ImplicitEventControl,
    ImplicitNonAnsiPort,
    ImplicitType,
    ImpliesPropertyExpr,
    IncludeDirective,
    InequalityExpression,
    InitialBlock,
    InsideExpression,
    InstanceConfigRule,
    InstanceName,
    IntType,
    IntegerLiteralExpression,
    IntegerType,
    IntegerVectorExpression,
    InterfaceDeclaration,
    InterfaceHeader,
    InterfacePortHeader,
    IntersectClause,
    IntersectSequenceExpr,
    InvocationExpression,
    JumpStatement,
    LessThanEqualExpression,
    LessThanExpression,
    LetDeclaration,
    LineDirective,
    LocalScope,
    LocalVariableDeclaration,
    LogicType,
    LogicalAndExpression,
    LogicalEquivalenceExpression,
    LogicalImplicationExpression,
    LogicalLeftShiftAssignmentExpression,
    LogicalOrExpression,
    LogicalRightShiftAssignmentExpression,
    LogicalShiftLeftExpression,
    LogicalShiftRightExpression,
    LongIntType,
    LoopConstraint,
    LoopGenerate,
    LoopStatement,
    MacroActualArgument,
    MacroActualArgumentList,
    MacroArgumentDefault,
    MacroFormalArgument,
    MacroFormalArgumentList,
    MacroUsage,
    MatchesClause,
    MemberAccessExpression,
    MinTypMaxExpression,
    ModAssignmentExpression,
    ModExpression,
    ModportClockingPort,
    ModportDeclaration,
    ModportExplicitPort,
    ModportItem,
    ModportNamedPort,
    ModportSimplePortList,
    ModportSubroutinePort,
    ModportSubroutinePortList,
    ModuleDeclaration,
    ModuleHeader,
    MultipleConcatenationExpression,
    MultiplyAssignmentExpression,
    MultiplyExpression,
    NameValuePragmaExpression,
    NamedArgument,
    NamedBlockClause,
    NamedLabel,
    NamedParamAssignment,
    NamedPortConnection,
    NamedStructurePatternMember,
    NamedType,
    NetAlias,
    NetDeclaration,
    NetPortHeader,
    NetTypeDeclaration,
    NewArrayExpression,
    NewClassExpression,
    NoUnconnectedDriveDirective,
    NonAnsiPortList,
    NonAnsiUdpPortList,
    NonblockingAssignmentExpression,
    NonblockingEventTriggerStatement,
    NullLiteralExpression,
    NumberPragmaExpression,
    OneStepDelay,
    OpenRangeExpression,
    OpenRangeList,
    OrAssignmentExpression,
    OrPropertyExpr,
    OrSequenceExpr,
    OrderedArgument,
    OrderedParamAssignment,
    OrderedPortConnection,
    OrderedStructurePatternMember,
    PackageDeclaration,
    PackageExportAllDeclaration,
    PackageExportDeclaration,
    PackageHeader,
    PackageImportDeclaration,
    PackageImportItem,
    ParallelBlockStatement,
    ParameterDeclaration,
    ParameterDeclarationStatement,
    ParameterPortList,
    ParameterValueAssignment,
    ParenExpressionList,
    ParenPragmaExpression,
    ParenthesizedBinsSelectExpr,
    ParenthesizedEventExpression,
    ParenthesizedExpression,
    ParenthesizedPattern,
    ParenthesizedPropertyExpr,
    ParenthesizedSequenceExpr,
    PathDeclaration,
    PathDescription,
    PatternCaseItem,
    PortConcatenation,
    PortDeclaration,
    PortReference,
    PostdecrementExpression,
    PostincrementExpression,
    PowerExpression,
    PragmaDirective,
    PrimaryBlockEventExpression,
    PrimitiveInstantiation,
    ProceduralAssignStatement,
    ProceduralDeassignStatement,
    ProceduralForceStatement,
    ProceduralReleaseStatement,
    Production,
    ProgramDeclaration,
    ProgramHeader,
    PropertyDeclaration,
    PropertySpec,
    PropertyType,
    PullStrength,
    PulseStyleDeclaration,
    QueueDimensionSpecifier,
    RandCaseItem,
    RandCaseStatement,
    RandJoinClause,
    RandSequenceStatement,
    RangeCoverageBinInitializer,
    RangeDimensionSpecifier,
    RealLiteralExpression,
    RealTimeType,
    RealType,
    RegType,
    RepeatedEventControl,
    ReplicatedAssignmentPattern,
    ResetAllDirective,
    RestrictPropertyStatement,
    ReturnStatement,
    RootScope,
    RsCase,
    RsCodeBlock,
    RsElseClause,
    RsIfElse,
    RsProdItem,
    RsRepeat,
    RsRule,
    RsWeightClause,
    SUntilPropertyExpr,
    SUntilWithPropertyExpr,
    ScopedName,
    SequenceDeclaration,
    SequenceMatchList,
    SequenceRepetition,
    SequenceType,
    SequentialBlockStatement,
    ShortIntType,
    ShortRealType,
    SignalEventExpression,
    SignedCastExpression,
    SimpleAssignmentPattern,
    SimpleBinsSelectExpr,
    SimplePathSuffix,
    SimplePragmaExpression,
    SimplePropertyExpr,
    SimpleRangeSelect,
    SimpleSequenceExpr,
    SolveBeforeConstraint,
    SpecifyBlock,
    SpecparamDeclaration,
    SpecparamDeclarator,
    StandardCaseItem,
    StandardPropertyCaseItem,
    StandardRsCaseItem,
    StreamExpression,
    StreamExpressionWithRange,
    StreamingConcatenationExpression,
    StringLiteralExpression,
    StringType,
    StrongWeakPropertyExpr,
    StructType,
    StructUnionMember,
    StructurePattern,
    StructuredAssignmentPattern,
    SubtractAssignmentExpression,
    SubtractExpression,
    SuperHandle,
    SystemName,
    SystemTimingCheck,
    TaggedPattern,
    TaggedUnionExpression,
    TaskDeclaration,
    ThisHandle,
    ThroughoutSequenceExpr,
    TimeLiteralExpression,
    TimeScaleDirective,
    TimeType,
    TimeUnitsDeclaration,
    TimingCheckCondition,
    TimingCheckEvent,
    TimingControlExpression,
    TimingControlStatement,
    TransListCoverageBinInitializer,
    TransRange,
    TransRepeatRange,
    TransSet,
    TypeAssignment,
    TypeParameterDeclaration,
    TypeReference,
    TypedefDeclaration,
    UdpBody,
    UdpDeclaration,
    UdpEdgeIndicator,
    UdpEntry,
    UdpInitialStmt,
    UdpInputPortDecl,
    UdpOutputPortDecl,
    UnaryBinsSelectExpr,
    UnaryBitwiseAndExpression,
    UnaryBitwiseNandExpression,
    UnaryBitwiseNorExpression,
    UnaryBitwiseNotExpression,
    UnaryBitwiseOrExpression,
    UnaryBitwiseXnorExpression,
    UnaryBitwiseXorExpression,
    UnaryLogicalNotExpression,
    UnaryMinusExpression,
    UnaryPlusExpression,
    UnaryPredecrementExpression,
    UnaryPreincrementExpression,
    UnaryPropertyExpr,
    UnarySelectPropertyExpr,
    UnbasedUnsizedLiteralExpression,
    UnconnectedDriveDirective,
    UndefDirective,
    UndefineAllDirective,
    UnionType,
    UniquenessConstraint,
    UnitScope,
    UntilPropertyExpr,
    UntilWithPropertyExpr,
    Untyped,
    UserDefinedNetDeclaration,
    VariableDimension,
    VariablePattern,
    VariablePortHeader,
    VirtualInterfaceType,
    VoidCastedCallStatement,
    VoidType,
    WaitForkStatement,
    WaitOrderStatement,
    WaitStatement,
    WildcardDimensionSpecifier,
    WildcardEqualityExpression,
    WildcardInequalityExpression,
    WildcardLiteralExpression,
    WildcardPattern,
    WildcardPortConnection,
    WildcardPortList,
    WildcardUdpPortList,
    WithClause,
    WithFunctionClause,
    WithFunctionSample,
    WithinSequenceExpr,
    XorAssignmentExpression,
};
#endif